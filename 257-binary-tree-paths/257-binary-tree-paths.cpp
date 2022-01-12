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
    vector <string> ans;
    void preorder(TreeNode* root,string s){
        if(root){
            if(root->left == NULL and root->right == NULL){
                s += to_string(root->val);
                ans.push_back(s);
                return;
            }
            s += to_string(root->val) + "->";
            if(root->left)  preorder(root->left,s);
            if(root->right) preorder(root->right,s);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root,"");
        return ans;
    }
};