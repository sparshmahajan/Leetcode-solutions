class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            int cost = prices[i] - low;
            profit = max(profit,cost);
            low = min(low,prices[i]);
        }
        return profit;
    }
};