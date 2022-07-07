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
    int Height (TreeNode* root,bool &res){
        if(root == NULL) return 0;
        int x,y;
        x = Height(root->left,res);
        y = Height(root->right,res);
        if(abs(x-y)>1) res = false;
        return x>y ? x+1 : y+1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) 
            return true;
        if (root->left==NULL and root->right==NULL) 
            return true;
        int x,y;
        bool res = true;
        x = Height(root->left,res);
        y = Height(root->right,res);
        if(abs(x-y)>1) 
            return false;
        return res;
    }
};