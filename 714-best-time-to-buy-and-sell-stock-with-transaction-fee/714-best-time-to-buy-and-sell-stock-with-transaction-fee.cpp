class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector <int> after(2,0), curr(2,0);
        for(int idx=n-1;idx>=0;idx--){
            curr[1] = max(-prices[idx] + after[0], after[1]);    
            curr[0] = max(prices[idx] - fee + after[1], after[0]);
            after = curr;
        }
        return after[1];

    }
};