/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(TreeNode *root, int targetSum, vector<int> ds, vector<vector< int>> &ans)
        {
            if (root == NULL)
                return;

            int subsum = targetSum - root->val;

            ds.push_back(root->val);

            if (subsum == 0 and root->left == NULL and root->right == NULL)
            {
                ans.push_back(ds);
                return;
            }

            if (root->left)
            {
                solve(root->left, subsum, ds, ans);
            }
            if (root->right)
            {
                solve(root->right, subsum, ds, ans);
            }
        }

    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector < int>> ans;
        vector<int> ds;
        solve(root, targetSum, ds, ans);

        return ans;
    }
};