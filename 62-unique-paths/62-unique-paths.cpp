class Solution
{
    public:
        int uniquePaths(int m, int n)
        {
            vector<vector < int>> dp(m, vector<int> (n, 0));
            for(int i=0;i<n;i++)
                dp[0][i] = 1;
            for(int i=0;i<m;i++)
                dp[i][0] = 1;
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    int move_up = 0;
                    int move_left = 0;
                    if (i >= 1)
                        move_left = dp[i - 1][j];
                    if (j >= 1)
                        move_up = dp[i][j - 1];

                    if (i != 0 && j != 0)
                        dp[i][j] = move_up + move_left;
                }
            }
            return dp[m - 1][n - 1];
        }
};