class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx < 2)
            return nums[idx];
        
        if(dp[idx] != -1)
            return dp[idx];
        int take = nums[idx] + solve(idx-2,nums,dp);
        int not_take =solve(idx-1,nums,dp);
        
        return dp[idx] = max(take,not_take);
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size()+1;
        int x = *max_element(nums.begin(),nums.end());
        vector <int> arr(x+1,0),dp(x+1,-1);
        for(auto x:nums)
            arr[x] += x;
        return solve(x,arr,dp);
    }
};