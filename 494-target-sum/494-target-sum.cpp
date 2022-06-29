class Solution {
public:
    int solve(int i,int expression,vector<int>& nums, int target,vector<map<int,int>>& dp){
        if(i == nums.size())
            return target == expression;
        
        if(dp[i].find(expression) != dp[i].end())
            return dp[i][expression];
        
        int add = solve(i+1,expression+nums[i],nums,target,dp);
        int minus = solve(i+1,expression-nums[i],nums,target,dp);
        
        return dp[i][expression] =add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<map<int,int>> dp(nums.size());
        return solve(0,0,nums,target,dp);
    }
};