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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        if(root == NULL) return false;
        int subsum = targetSum - root->val;
        if(subsum ==0 and root->left==NULL and root->right==NULL)
            ans = true;
        if(root->left)
            ans = ans or hasPathSum(root->left,subsum);
        if(root->right)
            ans = ans or hasPathSum(root->right,subsum);
        return ans;
    }
};