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
        int n = nums.size();
        vector <int> dp(n+1);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int not_pick = 0 + dp[i-1];
            int pick;
            if(i > 1)
                pick = nums[i] + dp[i-2];
            else
                pick = nums[i];
            
            dp[i] = max(pick,not_pick);
        }
        return dp[n-1];
    }
};