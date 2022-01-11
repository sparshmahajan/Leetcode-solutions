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
    int ans =0;
    void preorder(TreeNode* root, int csum){
        if(root){
            csum = (csum << 1) | root->val;
            if(root->left == NULL and root->right == NULL){
                ans += csum;
                return ;
            }
            preorder(root->left,csum);
            preorder(root->right,csum);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return ans;
    }
};