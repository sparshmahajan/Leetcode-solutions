class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ,i,res = 0,start = 0, curr;
        if(n < 2)
            return n;        
        map <char,int> mp;
        mp[s[0]] = 0;
        for(int i=1;i<n;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
                curr = i - start + 1;
                res = max(res,curr);
                continue;
            }
        
            int idx = mp[s[i]];
            mp[s[i]] = i;
            if(idx >= start){
                start = idx + 1;
            }
            curr = i - start + 1;
            res = max(res,curr);
        }
        return res;
    }
};