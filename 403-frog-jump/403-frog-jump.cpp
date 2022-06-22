class Solution
{
    public:
        bool solve(int idx, int k, int n, vector<int> &stones, unordered_map<int, int> &mp, vector< vector< int>> &dp)
        {
            if (idx == n - 1)
                return true;

            if (dp[idx][k] != -1)
                return dp[idx][k];

            bool t = false;
            for (int i = -1; i <= 1; i++)
            {
                if (mp[stones[idx] + k + i] > 0 && idx < mp[stones[idx] + k + i])
                {
                    bool res = solve(mp[stones[idx] + k + i], k + i, n, stones, mp, dp);
                    t = t or res;
                    dp[idx][k] = t;
                    if (t == 1)
                        return true;
                }
            }
            return dp[idx][k] = false;
        }

    bool canCross(vector<int> &stones)
    {
        unordered_map<int, int> mp;
        int n = stones.size();
        if (stones[1] != 1)
            return false;
        for (int i = 0; i < n; i++)
        {
            mp[stones[i]] = i;
        }
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(1, 1, n, stones, mp, dp);
    }
};