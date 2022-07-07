class Solution
{
    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            if (s1.size() + s2.size() != s3.size())
                return false;
            vector<vector < int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
            dp[0][0] = 1;
            for (int i = 0; i <= s1.size(); i++)
            {
                for (int j = 0; j <= s2.size(); j++)
                {
                    if (i == 0 and j == 0)
                    {
                        dp[i][j] = 1;
                        continue;
                    }
                    if (i > 0 and s1[i - 1] == s3[i + j - 1] and j > 0 and s2[j - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                    else if (i > 0 && s1[i - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i - 1][j];
                    else if (j > 0 && s2[j - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i][j - 1];
                    else
                        dp[i][j] = false;
                }
            }
            return dp[s1.size()][s2.size()];
        }
};