class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(),i;
        vector <vector<int>> dp (n+1, vector <int> (amount+1));
        for(i=1;i<=amount;i++)
            dp[0][i] = 0;
        for(i=0;i<=n;i++)
            dp[i][0] = 1;
        for(i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] > j){
                    //not take
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    //take
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];  
                }      
            }
        }
        if(dp[n][amount]==INT_MAX-100) return -1;
        return dp[n][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        return coinChange(coins,amount);
    }
};