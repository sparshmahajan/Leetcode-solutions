class Solution
{
    public:
        int uniquePathsWithObstacles(vector<vector < int>> &obstacleGrid)
        {
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            vector<int> prev(n, 0),curr(n,0);
            prev[0] = obstacleGrid[0][0] ? 0 : 1;
            for (int i = 1; i < n; i++)
            {
                if (obstacleGrid[0][i] != 1)
                    prev[i] = prev[i - 1];
            }

            for (int i = 1; i < m; i++)
            {
                curr[0] = obstacleGrid[i][0] ? 0 : prev[0];
                for (int j = 1; j < n; j++)
                {
                    if (obstacleGrid[i][j] == 1)
                        curr[j] = 0;
                    else
                    {
                        int move_up = 0;
                        int move_left = 0;
                        if (i >= 1)
                            move_left = prev[j];
                        if (j >= 1)
                            move_up = curr[j - 1];

                        curr[j] = move_up + move_left;
                    }
                }
                prev = curr;
            }

            return prev[n - 1];
        }
};