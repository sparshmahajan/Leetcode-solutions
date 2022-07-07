class Solution
{
    public:
        int numDistinct(string s, string t)
        {
            int m = s.size(), n = t.size();
            vector<vector <unsigned long>> dp(m + 1, vector<unsigned long> (n + 1, 0));
            for (int i = 0; i <= m; i++)
                dp[i][0] = 1;

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    unsigned long pick = 0, not_pick = 0;
                    
                    if (s[i - 1] == t[j - 1])
                        pick = dp[i - 1][j - 1];
                    not_pick = dp[i - 1][j];

                    dp[i][j] = pick + not_pick; 
                }
            }
            return dp[m][n];
        }
};