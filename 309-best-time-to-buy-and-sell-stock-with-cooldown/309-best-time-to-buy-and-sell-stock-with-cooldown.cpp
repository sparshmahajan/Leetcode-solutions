class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector <int> (2,0));
        for(int idx=n-1;idx>=0;idx--){
                dp[idx][1] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                
                dp[idx][0] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
        
        }
        return dp[0][1];
    }
};