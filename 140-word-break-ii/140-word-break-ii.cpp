class Solution {
public:
    void solve(int i,string &s, string k,unordered_map<string,int> &mp,vector <string> &ans){
        if(i==s.size()){
            k.pop_back();
            ans.push_back(k);
            return;
        }
        
        for(int idx=i+1;idx<=s.size();idx++){
            string t = s.substr(i,idx-i);
            if(mp.find(t) != mp.end()){
                solve(idx,s,k+t+" ",mp,ans);
            }
        }
    }
        
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        vector <string> ans;
        for(auto x:wordDict)
            mp[x]++;
        solve(0,s,"",mp,ans);
        return ans;
    }
};