/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root == NULL)
            return NULL;
        if(root == p or root == q)
            return root;
        if((root->val > p->val and root->val < q->val )or (root->val < p->val and root->val > q->val))
            return root;
        if(root->val > p->val)
            return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
        
    }
};