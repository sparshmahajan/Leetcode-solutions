class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i,vector <int>& nums,vector <int> temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        helper(i+1,nums,temp);
        temp.push_back(nums[i]);
        helper(i+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector <int> temp;
        helper(0,nums,temp);
        return ans;
    }
};