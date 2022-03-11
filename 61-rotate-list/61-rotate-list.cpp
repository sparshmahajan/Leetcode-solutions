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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 or !head)
        return head;
        
        ListNode *fast = head , *slow = head;
        
        int length = 1;
        while(fast->next != NULL){
            fast = fast->next;
            length++;
        }
        fast->next = head;
         k = k % length;
        int iteration = length - k;

        for(int i=0;i< iteration;i++){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = NULL;
        return slow;
    }
};