class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(),i;
        vector <vector<int>> dp (n+1, vector <int> (amount+1));
        dp[0][0]=0;
        for(i=1;i<=amount;i++)
            dp[0][i] = INT_MAX-100;
        for(i=0;i<=n;i++)
            dp[i][0] = 0;
        for(i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] > j){
                    //not take
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    //take
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);  
                }      
            }
        }
        if(dp[n][amount]==INT_MAX-100) return -1;
        return dp[n][amount];
    }
};