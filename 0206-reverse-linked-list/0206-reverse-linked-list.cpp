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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        // approach 1
        // ListNode *newHead=NULL;
        // while(head!=NULL)
        // {
        //     ListNode *next=head->next;
        //     head->next=newHead;
        //     newHead=head;
        //     head=next;
        // }
        // return newHead;

        // approach 2
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *nex=NULL;
        while(curr!=NULL)
        {
            
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head=prev;
        return head;
    }
   
       
};