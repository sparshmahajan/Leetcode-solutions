class Solution
{
    public:
        void solve(int i, int target, vector<int> &candidates, vector<int>&dp, vector< vector< int>> &ans)
        {
            if (target == 0)
            {
                ans.push_back(dp);
                return;
            }

            for (int idx = i; idx < candidates.size(); idx++)
            {
                if (idx > i and candidates[idx] == candidates[idx - 1])
                    continue;
                if (candidates[idx] > target)
                    break;

                dp.push_back(candidates[idx]);
                solve(idx + 1, target - candidates[idx], candidates, dp, ans);
                dp.pop_back();
            }
        }

    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> dp;
        vector<vector < int>> ans;
        solve(0, target, candidates, dp, ans);
        return ans;
    }
};