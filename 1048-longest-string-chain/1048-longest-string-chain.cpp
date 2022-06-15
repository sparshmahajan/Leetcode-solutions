class Solution {
public:
    int solve(int i,vector<string>& words,unordered_map <string,int>& mp,vector <int>& dp){
        if(dp[i] != -1)
            return dp[i];
        
        int len = 1;
        string str = words[i];
        
        for(int j=0;j<str.size();j++){
            string new_str = str;
            new_str.erase(j,1);
            if(mp[new_str] > 0){
                len = max(1 + solve(mp[new_str]-1,words,mp,dp),len);
            }
        }
        return dp[i] = len;
    }
    
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[words[i]] = i+1;
        }
        
        vector <int> dp(n,-1);
        
        int maxi = 1;
        for(int i=0;i<n;i++){
            maxi = max(solve(i,words,mp,dp),maxi);
        }
        return maxi;
    }
};