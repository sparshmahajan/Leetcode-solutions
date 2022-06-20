class Solution
{
    public:
        int maxProfit(int k, vector<int> &prices)
        {
            int n = prices.size();
            vector<int> after(2*k+1, 0), curr(2*k+1, 0);

            for (int idx = n - 1; idx >= 0; idx--)
            {
                for (int trans = 1; trans < (2*k)+1; trans++)
                {
                    int profit = 0;
                    if (trans % 2 == 0)
                    {
                        profit = max(-prices[idx] + after[trans - 1], after[trans]);
                    }
                    else
                    {
                        profit = max(prices[idx] + after[trans - 1], after[trans]);
                    }
                    curr[trans] = profit;
                }
                after = curr;
            }
            return after[2*k];
        }
};