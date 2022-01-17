class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector <int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
    
    bool helper(vector <int>& nums,int idx,vector <int>& dp){
        if(idx >= nums.size()-1) return true;
        int cur = nums[idx];
        if(cur >= nums.size()-idx) return true;
        if(dp[idx]!=-1) return dp[idx];
        
        bool a = false;
        for(int i =1;i<=cur;i++){
            bool t = helper(nums,idx+i,dp);
            a = a or t;
        }
        return dp[idx] = a;
    }
};