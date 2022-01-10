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
        ListNode *a = headA , *b = headB;
        while(a){
            while(b){
                if(a==b) return a;
                b=b->next;
            }
            b=headB;
            a=a->next;
        }
        return NULL;
    }
};