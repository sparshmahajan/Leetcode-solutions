class Solution
{
    public:
        int solve(int i, int j, string &s, string &t,vector<vector < int>> &dp)
        {
            if (i == 0)
                return i == j;

            if (j == 0)
                return 1;
            
            if(dp[i][j] != -1)
                return dp[i][j];

            int pick = 0, not_pick = 0;
            if (s[i - 1] == t[j - 1])
                pick = solve(i - 1, j - 1, s, t,dp);
            not_pick = solve(i - 1, j, s, t,dp);

            return dp[i][j] = pick + not_pick;
        }

    int numDistinct(string s, string t)
    {
        vector<vector < int>> dp(s.size() + 1, vector<int> (t.size() + 1, -1));
        return solve(s.size(), t.size(), s, t,dp);
    }
};