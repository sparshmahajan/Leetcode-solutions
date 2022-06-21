class Solution
{
    public:
        int minCost(int n, vector<int> &cuts)
        {
            int c = cuts.size();
            cuts.push_back(n);
            cuts.insert(cuts.begin(), 0);
            sort(cuts.begin(), cuts.end());
            vector<vector < int>> dp(c + 2, vector<int> (c + 2, 0));

            for (int i = c; i >= 1; i--)
            {
                for (int j = 1; j <= c; j++)
                {
                    if (i > j) continue;

                    int mini = 1e9;
                    for (int k = i; k <= j; k++)
                    {
                        int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                        mini = min(cost, mini);
                    }
                    dp[i][j] = mini;
                }
            }
            return dp[1][c];
        }
};