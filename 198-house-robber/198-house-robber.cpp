class Solution {
public:     
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int not_pick = 0 + dp[i-1];
            int pick;
            if(i > 1)
                pick = nums[i] + dp[i-2];
            else
                pick = nums[i];
            
            dp[i] = max(pick,not_pick);
        }
        return dp[n-1];
    }
};