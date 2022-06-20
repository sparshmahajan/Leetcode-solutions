class Solution {
public:
//     int solve(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp,int n){
//         if(idx >= n)
//             return 0;
        
//         if(dp[idx][buy] != -1)
//             return dp[idx][buy];
        
//         int profit = 0;
//         if(buy)
//             profit = max(-prices[idx] + solve(idx+1,0,prices,dp,n), 0 + solve(idx+1,1,prices,dp,n));
//         else
//             profit = max(prices[idx] + solve(idx+1,1,prices,dp,n), 0 + solve(idx+1,0,prices,dp,n));
        
//         return dp[idx][buy] = profit;
//     }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector <int> (2,0));
        for(int idx=n-1;idx>=0;idx--){
            dp[idx][1] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);    
            dp[idx][0] = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
        }
        return dp[0][1];
    }
};