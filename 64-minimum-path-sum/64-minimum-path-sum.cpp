class Solution
{
    public:
        int solve(int i, int j, vector<vector < int>> &grid,vector<vector<int>> &dp)
        {
            if (i == 0 && j == 0)
                return grid[0][0];
            
            if(dp[i][j] != -1)
                return dp[i][j];

            int ans = 1e9;
            if (j-1 >= 0)
                ans = min(ans, grid[i][j] + solve(i, j - 1, grid,dp));
            if (i-1 >= 0)
                ans = min(ans, grid[i][j] + solve(i - 1, j, grid,dp));
            
            return dp[i][j] = ans;
        }

    int minPathSum(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m - 1, n - 1, grid,dp);
    }
};