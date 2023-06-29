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
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(left&&right){
            if(left->val<=right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else
            {
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        if(left){
            mptr->next=left;
        }
        if(right){
            mptr->next=right;
        }
        return ans->next;
    }
};