class Solution {
public:
    int solve(vector<int>& job,int n, int idx,int d,vector <vector<int>>& dp){
        if( d == 1)
            return *max_element(begin(job) + idx, end(job));
        
        if(dp[idx][d] != -1)
            return dp[idx][d];
        
        int result = INT_MAX;
        int MAX = INT_MIN;
        for(int i = idx;i<= n-d;i++){
            MAX = max(MAX, job[i]);
            result = min(result, MAX + solve(job,n,i+1,d-1,dp));
        }
        return dp[idx][d] = result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        vector <vector<int>> dp(n + 1, vector <int> (d + 1,-1));
        return solve(jobDifficulty,n,0,d,dp);
    }
};