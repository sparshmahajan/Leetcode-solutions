class Solution {
public:
    
    void helper(int i,vector <int>& nums,vector <int> temp,vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        helper(i+1,nums,temp,ans);
        temp.push_back(nums[i]);
        helper(i+1,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> temp;
        vector<vector<int>> ans;
        helper(0,nums,temp,ans);
        return ans;
    }
};