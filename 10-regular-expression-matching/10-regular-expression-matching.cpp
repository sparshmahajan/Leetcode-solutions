class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            int n = s.size(), m = p.size();
            vector<vector < bool>> dp(n + 1, vector<bool> (m + 1, false));
            dp[0][0] = true;
            for (int j = 2; j <= m; j++)
            {
                if (p[j - 1] == '*')
                    dp[0][j] = dp[0][j - 2];
                else
                    dp[0][j] = false;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i - 1] == p[j - 1] or p[j - 1] == '.')
                        dp[i][j] = dp[i - 1][j - 1];

                    else if (p[j - 1] == '*')
                    {
                        if (p[j - 2] == s[i - 1] or p[j - 2] == '.')
                        {
                            dp[i][j] = dp[i - 1][j] or dp[i][j - 2];
                        }
                        else
                        {
                            dp[i][j] = dp[i][j - 2];
                        }
                    }
                    else
                        dp[i][j] = false;
                }
            }
            return dp[n][m];
        }
};