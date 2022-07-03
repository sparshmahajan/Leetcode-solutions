class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            vector<vector < int>> dp(n, vector<int> (n, -1));
            for (int i = 0; i < n; i++)
            {
                dp[0][i] = matrix[0][i];
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int ans = 1e9;
                    if (i - 1 >= 0)
                    {
                        ans = min(ans, matrix[i][j] + dp[i - 1][j]);
                    }
                    if (i - 1 >= 0 and j + 1 < matrix[0].size())
                    {
                        ans = min(ans, matrix[i][j] + dp[i - 1][j + 1]);
                    }
                    if (i - 1 >= 0 and j - 1 >= 0)
                    {
                        ans = min(ans, matrix[i][j] + dp[i - 1][j - 1]);
                    }

                    dp[i][j] = ans;
                }
            }
            return* min_element(dp[n - 1].begin(), dp[n - 1].end());
        }
};