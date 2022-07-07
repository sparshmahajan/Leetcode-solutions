/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int &count,int max){
        if(root == NULL)
            return;
        
        if(root->val >= max){
            max = root->val;
            count++;
        }
        
        solve(root->left,count,max);
        solve(root->right,count,max);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max = root->val;
        solve(root,count,max);
        return count;
    }
};