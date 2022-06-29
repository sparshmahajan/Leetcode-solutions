class Solution
{
    public:
        void solve(int i, int n, int k, vector<int> ds, vector<vector< int>> &ans)
        {
            if (k == 0)
            {
                ans.push_back(ds);
                ds.clear();
                return;
            }

            for (int idx = i; idx <= n; idx++)
            {
                ds.push_back(idx);
                solve(idx + 1, n, k - 1, ds, ans);
                ds.pop_back();
            }
        }

    vector<vector < int>> combine(int n, int k)
    {
        vector<vector < int>> ans;
        vector<int> ds;
        solve(1, n, k, ds, ans);
        return ans;
    }
};