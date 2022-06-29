class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int max_sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        vector<map<int,int>> dp(n+1);
        dp[n][target] = 1;
        
        for(int i=n-1;i>=0;i--){
            for(int expression=max_sum;expression >= -max_sum;expression--){
                int add = dp[i+1][expression+nums[i]];
                int minus = dp[i+1][expression-nums[i]];
                
                dp[i][expression] =add+minus;
            }
        }
        return dp[0][0];
    }
};