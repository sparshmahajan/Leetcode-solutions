class Solution {
public:
    int solve(int idx,int trans,vector<int>& prices,vector<vector<int>>& dp,int n){
        if(idx >= n)
            return 0;
        if(trans < 0)
            return 0;
        
        if(dp[idx][trans] != -1)
           return dp[idx][trans];
        
        int profit = 0;
        if(trans % 2 == 0){
            profit = max(-prices[idx] + solve(idx+1,trans-1,prices,dp,n), solve(idx+1,trans,prices,dp,n));
        } else{
           profit = max(prices[idx] + solve(idx+1,trans-1,prices,dp,n),solve(idx+1,trans,prices,dp,n));
        }
        
        return dp[idx][trans] = profit;
    }
        
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return solve(0,4,prices,dp,n);
    }
};