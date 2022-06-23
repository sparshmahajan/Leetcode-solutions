class Solution
{
    public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector < int>> dp(n+1, vector<int> (n+1, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prev = idx - 1; prev >= -1; prev--)
            {
                int len = dp[idx+1][prev+1];
                if (prev == -1 || nums[idx] > nums[prev])
                    len = max(len, 1 + dp[idx+1][idx+1]);

                dp[idx][prev + 1] = len;
            }
        }
        return dp[0][0];
    }
};