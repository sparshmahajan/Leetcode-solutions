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
    TreeNode* generateTree(vector <int> v,int i,int j){
        if(i>j) return NULL;
        if(i==j) return new TreeNode(v[i]);
        int m = (i+j)/2;
        TreeNode *t = new TreeNode(v[m]);
        t->left = generateTree(v,i,m-1);
        t->right = generateTree(v,m+1,j);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generateTree(nums,0,nums.size()-1);
    }
};