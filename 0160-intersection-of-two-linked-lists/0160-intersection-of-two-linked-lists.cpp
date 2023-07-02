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


        // unordered_map<ListNode*,int>map;

        // while(headA || headB){
        //     if(headA){
        //         if(map[headA]++){
        //             return headA;
        //         }
                
        //         headA=headA->next;
        //     }
        //     if(headB){
        //         if(map[headB]++){
        //             return headB;
        //         }
        //         headB=headB->next;
        //     }


        // }
        // return NULL;
        int n=1,m=1;
        ListNode *p1=headA;
        ListNode *p2=headB;
        while(p1!=NULL)
        {
            p1=p1->next;
            n++;
        }
        while(p2!=NULL)
        {
            p2=p2->next;
            m++;
        }
        p1=headA;
        p2=headB;
        int z=abs(m-n);
        if(m>n)
        {
            while(z)
            {
                p2=p2->next;
                z--;
            }
        }
        else if(n>m)
        {
            while(z)
            {
                p1=p1->next;
                z--;
            }
        }
        while(p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};