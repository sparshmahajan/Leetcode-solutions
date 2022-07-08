class Solution
{
    public:
        int solve(int i, int j, int k, int l, vector<vector < int>> &grid,vector<vector<vector< vector< int >>>> &dp)
        {
            if (i == 0 and j == 0)
                return grid[i][j];

            if (i < 0 or j < 0 or k < 0 or l < 0)
                return -1e9;

            if (grid[i][j] == -1 or grid[k][l] == -1)
                return -1e9;

            if (dp[i][j][k][l] != -1)
                return dp[i][j][k][l];

            int val = grid[i][j];
            if (i != k)
                val += grid[k][l];

            int downright = val + solve(i - 1, j, k, l - 1, grid,dp);
            int downdown = val + solve(i - 1, j, k - 1, l, grid,dp);
            int rightdown = val + solve(i, j - 1, k - 1, l, grid,dp);
            int rightright = val + solve(i, j - 1, k, l - 1, grid,dp);

            return dp[i][j][k][l] = max(max(downright, downdown), max(rightdown, rightright));
        }
    
    int cherryPickup(vector<vector < int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector< vector< int >>>> dp(n, vector<vector<vector< int>>> (n,vector<vector< int>>(n,vector<int> (n, -1))));
        int ans = solve(n - 1, n - 1, n - 1, n - 1, grid,dp);
        return ans < 0 ? 0 : ans;
    }
};