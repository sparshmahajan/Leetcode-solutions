class Solution {
public:
    bool solve(string s, vector<string>& wordDict,unordered_map<string,bool> &mp){
        if(s.size() == 0)
            return true;
        if(mp.find(s) != mp.end())
            return mp[s];
                
        for(int i=1;i<=s.size();i++){
            string t = s.substr(0,i);
            auto x = find(wordDict.begin(),wordDict.end(),t);
            if(x != wordDict.end() && solve(s.substr(i),wordDict,mp))
                return mp[s] = true;
        }
        return mp[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        return solve(s,wordDict,mp);
    }
};