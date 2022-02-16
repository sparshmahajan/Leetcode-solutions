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
    ListNode* recurSwap(ListNode *root){
        // base case : when root goes to end of linkedlist or when there
        // is only one elemnt in linked list
        if(root==NULL || root->next==NULL){
            return root;
        }
        
        ListNode* temp=root->next;
        ListNode* tempnext=temp->next;
        
        temp->next=root;
        root->next=recurSwap(tempnext);
        
        // here we are returining temp as the temp become head of the 
        // list after recursion in each iteration
        return temp;
    }
    
    ListNode* swapPairs(ListNode* head) {
        head=recurSwap(head);
        return head;
    }
};