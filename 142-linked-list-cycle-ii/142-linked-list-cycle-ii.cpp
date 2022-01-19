/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * }*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return NULL;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        
        
        while(fast && fast->next && fast != slow){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        if(!fast || !fast->next){
            return nullptr;
        }
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};