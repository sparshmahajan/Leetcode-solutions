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
        vector <int> after(2,0), curr(2,0);
        for(int idx=n-1;idx>=0;idx--){
            curr[1] = max(-prices[idx] + after[0], after[1]);    
            curr[0] = max(prices[idx] + after[1], after[0]);
            after = curr;
        }
        return after[1];
    }
};