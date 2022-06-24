class Solution
{
    public:
        bool solve(int i, int j, string &s, string &p, vector<vector < int>> &dp)
        {
            if (i == 0 && j == 0)
                return true;
            if (i > 0 && j == 0)
                return false;
            
            if (dp[i][j] != -1)
                return dp[i][j];
            
            if (j > 0 && i == 0)
            {
                if(p[j-1] == '*')
                    return solve(i,j-2,s,p,dp);
                return false;
            }

            if (s[i - 1] == p[j - 1] or p[j - 1] == '.')
                return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

            if (p[j - 1] == '*')
            {
                if (p[j - 2] == s[i - 1] or p[j - 2] == '.')
                {
                    dp[i][j] = solve(i - 1, j, s, p, dp) or solve(i, j - 2, s, p, dp);
                }
                else
                {
                    dp[i][j] = solve(i, j - 2, s, p, dp);
                }
                return dp[i][j];
            }

            return dp[i][j] = false;
        }

    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(n, m, s, p, dp);
    }
};