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
    ListNode* sortList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        multiset <int> s;
        while(head){
            s.insert(head->val);
            head=head->next;
        }
        ListNode *front = NULL, *rear = NULL,*t;
        for(auto x : s){
            if(front == NULL){
                t = new ListNode(x);
                rear = front = t;
            }
            else{
               t = new ListNode(x);
                rear->next = t;
                rear = rear-> next;
            }
            t = NULL;
        }
        return front;
    }
};