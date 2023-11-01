class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head &&(head->val == val)){
            ListNode *temp = head;
            head = head -> next;
            delete(temp);
        }
        ListNode *q = head, *p = head;
        while(p!=NULL){
            if(p->val == val){
                ListNode *temp = p;
                q->next = p->next;
                p = p->next;
            }
            else{
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};