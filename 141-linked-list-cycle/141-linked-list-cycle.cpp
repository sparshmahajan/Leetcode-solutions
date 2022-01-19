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
    bool hasCycle(ListNode *head) {
        if(!head or !head->next) return false;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast and fast->next and fast!=slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(!fast or !fast->next) return false;
        return true;
    }
};