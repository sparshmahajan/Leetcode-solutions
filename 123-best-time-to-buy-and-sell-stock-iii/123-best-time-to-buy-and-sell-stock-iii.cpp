class Solution {
public:
//     int solve(int idx,int trans,vector<int>& prices,vector<vector<int>>& dp,int n){
//         if(idx >= n)
//             return 0;
//         if(trans == 0)
//             return 0;
        
//         if(dp[idx][trans] != -1)
//            return dp[idx][trans];
        
//         int profit = 0;
//         if(trans % 2 == 0){
//             profit = max(-prices[idx] + solve(idx+1,trans-1,prices,dp,n), solve(idx+1,trans,prices,dp,n));
//         } else{
//            profit = max(prices[idx] + solve(idx+1,trans-1,prices,dp,n),solve(idx+1,trans,prices,dp,n));
//         }
        
//         return dp[idx][trans] = profit;
//     }
        
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(5,0) , curr(5,0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int trans=1;trans<5;trans++){
                int profit = 0;
                if(trans % 2 == 0){
                    profit = max(-prices[idx] + after[trans-1], after[trans]);
                } else{
                     profit = max(prices[idx] + after[trans-1],after[trans]);
                }
                curr[trans] = profit;
            }
            after = curr;
        }
        return after[4];
    }
};