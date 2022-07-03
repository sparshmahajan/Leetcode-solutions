class Solution
{
    public:
        int minPathSum(vector<vector < int>> &grid)
        {
            int m = grid.size(), n = grid[0].size();
            vector<int> prev(n, 0),curr(n,0);
            prev[0] = grid[0][0];
            for (int i = 1; i < n; i++)
                prev[i] = grid[0][i] + prev[i-1];

            for (int i = 1; i < m; i++)
            {
                curr[0] = grid[i][0] + prev[0];
                for (int j = 1; j < n; j++)
                {
                    int ans = 1e9;
                    ans = min(ans, grid[i][j] + curr[j - 1]);
                    ans = min(ans, grid[i][j] + prev[j]);

                    curr[j] = ans;
                }
                prev = curr;
            }

            return prev[n-1];
        }
};