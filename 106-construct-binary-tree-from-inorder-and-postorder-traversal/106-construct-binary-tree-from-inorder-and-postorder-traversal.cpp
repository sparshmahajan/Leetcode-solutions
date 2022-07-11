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
    TreeNode* solve(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map< int, int> &mp)
        {
            if (postStart > postEnd or inStart > inEnd)
                return NULL;

            TreeNode *root = new TreeNode(postorder[postEnd]);
            
            int inRoot = mp[root->val];
            int leftNums = inRoot - inStart;
            
            root->left = solve(postorder,postStart,postStart+leftNums-1,inorder,inStart,inRoot-1,mp);
            root->right = solve(postorder,postStart+leftNums,postEnd-1,inorder,inRoot+1,inEnd,mp);
            
            return root;
        }

    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode *root = solve(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size(), mp);
        return root;
    }
};