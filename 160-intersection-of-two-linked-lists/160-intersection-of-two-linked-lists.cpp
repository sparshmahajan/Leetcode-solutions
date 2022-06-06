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
        if(headA == NULL or headB == NULL) return NULL;
        int a=0,b=0;
        ListNode *t = headA;
        while(t){
            a++;
            t=t->next;
        }
        t = headB;
        while(t){
            b++;
            t=t->next;
        }
        if(a>b){
            a=a-b;
            while(a--) headA=headA->next;
        }
        else{
            a=b-a;
            while(a--) headB=headB->next;
        }
        while(headA and headB and (headA!=headB)){
            headA=headA->next;
            headB=headB->next;
        }
        if(headA==headB) return headA;
        return NULL;
    }
};