/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1==NULL)
//         {
//             return list2;
//         }
//         if(list2==NULL)
//         {
//             return list1;
//         }
//         ListNode *dummy;
//         dummy=new ListNode();
//         ListNode *temp=dummy;
//         while(list1 && list2)
//         {
//             if(list1->val<list2->val)
//             {
//                 temp->next=list1;
//                 list1=list1->next;
//             }
//             else
//             {
//                 temp->next=list2;
//                 list2=list2->next;
//             }
//             temp=temp->next;
//         }
//         if(list1)
//         {
//             temp->next=list1;
//         }
//         if(list2)
//         {
//             temp->next=list2;
//         }
//         return dummy->next;
//     }
// };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        // Check if one of the lists is empty
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        // Create a new dummy node as the starting point for the merged list
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans; // Create a pointer to the current node in the merged list

        // Iterate until either of the input lists reaches its end
        while (left && right) {
            if (left->val <= right->val) {
                // If the value in the left list is smaller, append it to the merged list
                mptr->next = left;
                mptr = left; // Move the pointer to the current node to the newly appended node
                left = left->next; // Move to the next node in the left list
            } else {
                // If the value in the right list is smaller, append it to the merged list
                mptr->next = right;
                mptr = right; // Move the pointer to the current node to the newly appended node
                right = right->next; // Move to the next node in the right list
            }
        }

        // Append the remaining nodes from the non-empty list
        if (left) {
            mptr->next = left;
        }
        if (right) {
            mptr->next = right;
        }

        return ans->next; // Return the merged list (excluding the dummy node)
    }
};
