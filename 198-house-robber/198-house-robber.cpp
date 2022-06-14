class Solution {
public:
    int solve(int idx,vector <int>& nums,vector <int>& dp){
        if(idx == 0)
            return dp[idx] = nums[idx];
        if(idx < 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
                
        int pick = nums[idx] + solve(idx-2,nums,dp);
        int not_pick = 0 + solve(idx-1,nums,dp);
        
        return dp[idx] = max(pick,not_pick);
    }
        
        
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector <int> dp(n+1,-1);
        return solve(n,nums,dp);
    }
};