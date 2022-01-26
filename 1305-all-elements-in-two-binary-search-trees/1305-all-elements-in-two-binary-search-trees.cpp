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
    void inorder(TreeNode* root,vector <int>& ans){
        if(root){
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> ans;
        inorder(root1,ans);
        int x = ans.size();
        int i=0,j=x;
        inorder(root2,ans);
        int n = ans.size();
        vector <int> res;
        while(i<x and j<n){
            if(ans[i]>ans[j]){
                res.push_back(ans[j]);
                j++;
            }
            else{ 
                res.push_back(ans[i]);
                i++;  
            }
        }
        while(i<x){
            res.push_back(ans[i]);
            i++; 
        }
        while(j<n){
            res.push_back(ans[j]);
            j++; 
        }
        return res;
    }
};