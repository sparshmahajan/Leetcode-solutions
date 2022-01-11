class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sum=0,res=0;
        for(int i=1;i<n;i++){
            sum=max(sum+prices[i]-prices[i-1],prices[i]-prices[i-1]);
            res=max(res,sum);
        }
        return res;
    }
};