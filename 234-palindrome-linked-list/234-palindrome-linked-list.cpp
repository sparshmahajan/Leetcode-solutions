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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        vector <int> v;
        ListNode* p = head;
        while(p){
            v.push_back(p->val);
            p=p->next;
        }
        for(int i=0,j=v.size()-1;i<=(v.size()/2);i++){
            if(v[i]!=v[j--]) return false;
        }
        return true;
    }
};