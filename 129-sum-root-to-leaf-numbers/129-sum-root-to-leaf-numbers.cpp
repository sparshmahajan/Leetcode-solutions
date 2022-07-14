/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void preorder(TreeNode *root, int sum,int &ans)
        {
            if (!root->left and!root->right)
            {
                ans += sum *10 + root->val;
                return;
            }

            sum = (sum *10) + root->val;
            if (root->left)
                preorder(root->left, sum, ans);
            if (root->right)
                preorder(root->right, sum, ans);
        }

    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        preorder(root,0,ans);
        return ans;
    }
};