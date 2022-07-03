class Solution
{
    public:
        int wiggleMaxLength(vector<int> &nums)
        {
            int n = nums.size();
            vector<vector < int>> dp(nums.size(), vector<int> (2, 0));
            dp[n - 1][0] = dp[n - 1][1] = 1;

            for (int i = n - 2; i >= 0; i--)
            {
                
                for (int flag = 0; flag <= 1; flag++)
                {
                    int ans = 0;
                    if (flag)
                    {
                        if (nums[i + 1] > nums[i])
                            ans = max(ans, 1 + dp[i + 1][0]);
                        else
                            ans = max(ans, dp[i + 1][1]);
                    }
                    else
                    {
                        if (nums[i + 1] < nums[i])
                            ans = max(ans, 1 + dp[i + 1][1]);
                        else
                            ans = max(ans, dp[i + 1][0]);
                    }

                    dp[i][flag] = ans;
                }
            }
            return max(dp[0][0], dp[0][1]);
        }
};