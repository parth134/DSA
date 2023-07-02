/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        unordered_map<ListNode*,int>map;

        while(headA || headB){
            if(headA){
                if(map[headA]++){
                    return headA;
                }
                
                headA=headA->next;
            }
            if(headB){
                if(map[headB]++){
                    return headB;
                }
                headB=headB->next;
            }


        }
        return NULL;
    }
};