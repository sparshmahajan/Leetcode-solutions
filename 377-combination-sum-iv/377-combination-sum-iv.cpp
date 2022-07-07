class Solution
{
    public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned long> dp(target+1,0);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            unsigned long ans = 0;
            for (int j = 0; j < nums.size();j++){
                if(i-nums[j] >= 0)
                    ans += dp[i-nums[j]];
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};