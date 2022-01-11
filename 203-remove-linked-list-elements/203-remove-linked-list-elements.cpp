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
    ListNode* removeElements(ListNode* head, int val) {
       // if(head == NULL) return NULL;
        ListNode* t =NULL;
        while(head and head->val == val){
            t = head;
            head = head->next;
            delete t;
        }
        if(head == NULL) return NULL;
        ListNode* p = head;
        while(p and p->next){
            if(p->next->val == val){
                t = p->next;
                p->next = t->next;
                delete t;
            }
            else
                p=p->next;
        }
        return head;
    }
};