class Solution
{
    public:
        int solve(int i, int flag, vector<int> &nums,vector<vector<int>>& dp)
        {
            if (i == nums.size()-1)
                return 1;

            if(dp[i][flag] != -1)
                return dp[i][flag];
            
            int ans = 0;
            if (flag)
            {
                if (nums[i + 1] > nums[i])
                    ans = max(ans, 1 + solve(i + 1, 0, nums,dp));
                else
                    ans = max(ans, solve(i + 1, 1, nums,dp));
            }
            else
            {
                if (nums[i + 1] < nums[i])
                    ans = max(ans, 1 + solve(i + 1, 1, nums,dp));
                else
                    ans = max(ans, solve(i + 1, 0, nums,dp));
            }
            
            return dp[i][flag] = ans;
        }

    int wiggleMaxLength(vector<int> &nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return max(solve(0,1,nums,dp),solve(0,0,nums,dp));
    }
};