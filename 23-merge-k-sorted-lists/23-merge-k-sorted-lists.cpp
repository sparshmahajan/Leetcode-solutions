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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode *head = lists[0];
        for(int i=1;i<lists.size();i++){
            head=merge(lists[i],head);
        }
        return head;
    }
    ListNode* merge(ListNode *p,ListNode *q){
        ListNode* start = new ListNode(-99);
        ListNode* head = new ListNode;
        head = start;
        while(p and q){
            if(p->val < q->val){
                start->next = p;
                p = p->next;
            }
            else{
                start->next = q;
                q = q->next;
            }
            start = start->next;
        }
        while(p){
           start->next = p;
            start = start->next;
            p = p->next; 
        }
        while(q){
           start->next = q;
            start = start->next;
            q = q->next; 
        }
        return head->next;
    }
};