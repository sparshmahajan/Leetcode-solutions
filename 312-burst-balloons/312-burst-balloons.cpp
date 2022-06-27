class Solution
{
    public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector < int>> dp(n + 2, vector<int> (n + 2, 0));
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                else
                {
                    int maxCoins = INT_MIN;
                    for (int k = i; k <= j; k++)
                    {
                        int cost = nums[i - 1] *nums[k] *nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                        maxCoins = max(maxCoins, cost);
                    }
                    dp[i][j] = maxCoins;
                }
            }
        }
        return dp[1][n];
    }
};