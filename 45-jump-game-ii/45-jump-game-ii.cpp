class Solution {
public:
    int jump(vector<int>& nums) {
        vector <int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
    
    int helper(vector <int>& nums,int idx,vector <int>& dp){
        if(idx >= nums.size()-1)
            return 0; 
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int ans = INT_MAX-10;
        for(int i=1;i<=nums[idx];i++){
                ans = min(ans, 1 + helper(nums,idx+i,dp));
        }
        return dp[idx] = ans;
    }
};