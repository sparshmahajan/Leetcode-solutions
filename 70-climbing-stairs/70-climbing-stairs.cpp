class Solution {
public:
    int climbStairs(int n) {
      vector <int> dp(n,-1);
       int ans=helper(0,n,dp);
        return ans;
    }
    int helper(int cur,int n,vector <int>& dp){
          if(cur>n)
            return 0;
          if(cur==n)
            return 1;
        if(dp[cur]!=-1)
            return dp[cur];
        
        int ans=helper(cur+1,n,dp)+helper(cur+2,n,dp);
        dp[cur]=ans;
        return ans;
     
    }
};