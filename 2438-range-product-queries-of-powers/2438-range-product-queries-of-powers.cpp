class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector <int> powers;
        for(int i=0;i<32;i++){
            int mask = 1<<i;
            if(n & mask)
                powers.push_back(mask);
        }
        
        vector<int> ans;
        for(auto x : queries){
            int i = x[0];
            long res = powers[i++];
            while(i <= x[1])
                res = ((long)res * powers[i++]) % mod;
            ans.push_back(res);
        }
        return ans;
    }
};