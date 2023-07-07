/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// assuming 64-bit system
static_assert(sizeof(uintptr_t) == 8);
// number of extra bits that are unused in the pointers.
// we could technically make do with just 15 bits
// since the range of vals is between [-10000, 10000], i.e. 20001 numbers
// and pow(2, 15) == 32768 is enough to store all these nums.
constexpr uint64_t NUM_EXTRA_BITS = 16;
constexpr uint64_t VAL_SHIFT = 64 - NUM_EXTRA_BITS;
constexpr uint64_t make_mask(uint64_t num_bits) {
    return (1ULL << num_bits) - 1;
}
constexpr uint64_t PTR_BITS = make_mask(VAL_SHIFT);
constexpr uint64_t VAL_BITS = make_mask(NUM_EXTRA_BITS) << VAL_SHIFT;
// make sure there is no overlap
static_assert((PTR_BITS & VAL_BITS) == 0);

struct Node2 {
    uint64_t tagged;
    struct Node2* next;
    struct Node2* random;
    int get_v() const {
        return tagged >> VAL_SHIFT;
    }
    void put_v(int v) {
        tagged |= uint64_t(v) << VAL_SHIFT;
    }
    void* get_ptr() const {
        return (void*)(tagged & PTR_BITS); 
    }
    void put(void* ptr, int v) {
        // zero-ing out the field is really crucial to avoid undefined behaviour
        // without this line, we can't be sure about the contents of padding bytes
        tagged = 0;
        put_ptr(ptr);
        put_v(v);
    }
    void put_ptr(void* ptr) {
        assert((int64_t(ptr) & VAL_BITS) == 0);
        tagged |= (int64_t)ptr;
    }
};
// this solution will break if the following assert is false
static_assert(sizeof(Node2) == sizeof(Node));

class Solution {
public:

    Node* copyRandomList(Node* head) {
        Node *copyhead = nullptr, *copytail = nullptr;

        // create copy list and add tagged pointers
        for (Node* p = head; p; p = p->next) {
            auto copy = new Node(p->val);
            if (!copyhead) {
                copyhead = copy;
            }
            if (copytail) {
                copytail->next = copy;
            }
            copytail = copy;
            copy->random = p->random;
            auto* origptr = reinterpret_cast<Node2*>(p);
            // store address of copied node into the original node using pointer tagging
            origptr->put(copy, copy->val);
        }
        // get the addresses from tagged pointer
        for (Node* copy = copyhead; copy; copy = copy->next) {
            if (copy->random) {
                // copy->random is currently the original random node
                auto* taggedptr = reinterpret_cast<Node2*>(copy->random);
                // get the copied node from the original node
                copy->random = (Node*)taggedptr->get_ptr();
            }
        }
        // restore the original values
        for (Node* p = head; p; p = p->next) {
            auto* taggedptr = reinterpret_cast<Node2*>(p);
            p->val = taggedptr->get_v();
        }
        return copyhead;
    }
};