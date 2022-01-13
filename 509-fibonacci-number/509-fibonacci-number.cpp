class Solution {
public:
    int helper(vector <int>& dp,int n){
        if(n == 0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n] = helper(dp,n-1) + helper (dp,n-2);
        return dp[n];
    }
    int fib(int n) {
        vector <int> dp(n+1,-1);
        return helper(dp,n);
    }
};