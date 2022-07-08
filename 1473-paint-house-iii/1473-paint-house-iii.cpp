class Solution {
public:
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int i,int nbr,int left,vector<vector<vector<int>>> &dp){
        if( i == m)
            return target == nbr ? 0 : 1e9;
        
        if(nbr > target)
            return 1e9;
        
        if(dp[i][nbr][left] != -1)
            return dp[i][nbr][left];
        
        if(houses[i] == 0){
            int ans = 1e9;
            for(int c=1;c<=n;c++){
                int new_nbr = (c == left) ? nbr : nbr+1;
                ans = min(ans,cost[i][c-1] + solve(houses,cost,m,n,target,i+1,new_nbr,c,dp));
            }
            return dp[i][nbr][left] = ans;
        }else{
            int new_nbr = (houses[i] == left) ? nbr : nbr+1;
            return dp[i][nbr][left] = solve(houses,cost,m,n,target,i+1,new_nbr,houses[i],dp);
        }
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (target+1,vector<int> (n+1,1e9)));
        for(int i=0;i<=n;i++){
            dp[m][target][i] = 0;
        }
        
        for(int i=m-1;i>=0;i--){
            for(int nbr=target;nbr>=0;nbr--){
                for(int left=n;left>=0;left--){
                    if(houses[i] == 0){
                        int ans = 1e9;
                        for(int c=1;c<=n;c++){
                            int new_nbr = (c == left) ? nbr : nbr+1;
                            ans = min(ans,cost[i][c-1] + solve(houses,cost,m,n,target,i+1,new_nbr,c,dp));
                        }
                        dp[i][nbr][left] = ans;
                    }else{
                        int new_nbr = (houses[i] == left) ? nbr : nbr+1;
                        dp[i][nbr][left] = solve(houses,cost,m,n,target,i+1,new_nbr,houses[i],dp);
                    }
                }
            }
        }
        int ans = dp[0][0][0];
        return ans == 1e9 ? -1 : ans;
    }
};