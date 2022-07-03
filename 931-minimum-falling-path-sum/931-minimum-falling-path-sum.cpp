class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            vector<int> prev(n, 0) , curr(n,0);
            for (int i = 0; i < n; i++)
            {
                prev[i] = matrix[0][i];
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int ans = 1e9;
                    if (i - 1 >= 0)
                    {
                        ans = min(ans, matrix[i][j] + prev[j]);
                    }
                    if (i - 1 >= 0 and j + 1 < matrix[0].size())
                    {
                        ans = min(ans, matrix[i][j] + prev[j + 1]);
                    }
                    if (i - 1 >= 0 and j - 1 >= 0)
                    {
                        ans = min(ans, matrix[i][j] + prev[j - 1]);
                    }

                    curr[j] = ans;
                }
                prev = curr;
            }
            return* min_element(prev.begin(),prev.end());
        }
};