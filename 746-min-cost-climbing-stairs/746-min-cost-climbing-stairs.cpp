class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        vector <int> dp(n+1,-1);
        int total1 = helper(cost,n,dp);
        int total2 = helper(cost,n-1,dp);
        cout<<total1<<" "<<total2<<endl;
        for(int i : dp) cout<<i<<" ";
        return min(total1,total2);
    }
    
    int helper(vector <int>& cost,int i,vector <int>& dp){
        if(i < 2) return cost[i];
        if(dp[i]!=-1) return dp[i];
        
        dp[i] = cost[i]+min(helper(cost,i-1,dp),helper(cost,i-2,dp));
        return dp[i];
    }
};