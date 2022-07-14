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
        void preorder(TreeNode *root, int sum, vector<int> &ans)
        {
            if (!root->left and!root->right)
            {
                ans.push_back(sum *10 + root->val);
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
        vector<int> ans;
        preorder(root, 0, ans);
        int sum = accumulate(ans.begin(), ans.end(), 0);
        return sum;
    }
};