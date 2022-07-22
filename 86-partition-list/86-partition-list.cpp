/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* partition(ListNode *head, int x)
        {
            ListNode *small_head = new ListNode(-1);
            ListNode *large_head = new ListNode(-1);
            ListNode *small = small_head;
            ListNode *large = large_head;
            while (head)
            {
                if (head->val < x)
                {
                    small->next = head;
                    head = head->next;
                    small = small->next;
                    small->next = NULL;
                }
                else
                {
                    large->next = head;
                    head = head->next;
                    large = large->next;
                    large->next = NULL;
                }
            }
            small->next = large_head->next;
            return small_head->next;
        }
};