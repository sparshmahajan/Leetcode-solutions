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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int i = 0;
        long long sum = 0;
        while(q.size() > 1){
            root = q.front();
            q.pop();
            
            if(root == NULL){
                double res = (double)sum/i;
                ans.push_back(res);
                q.push(NULL);
                sum = 0;
                i = 0;
            }
            else{
                sum += root->val;
                i++;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        if(i > 0){
            double res = (double)sum/i;
            ans.push_back(res);
        }
        return ans;
    }
};