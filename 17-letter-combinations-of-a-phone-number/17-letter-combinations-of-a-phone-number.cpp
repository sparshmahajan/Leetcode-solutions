class Solution {
public:
    void solve(int idx,string& digits,string s,vector<string>& ans,map <char,string>& mp){
        if(idx == 0){
            ans.push_back(s);
            return;
        }

        for(int i=0;i<mp[digits[idx-1]].size();i++){
            string t = mp[digits[idx-1]];
            solve(idx-1,digits,t[i]+s,ans,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        map <char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(digits.size(),digits,"",ans,mp);
        return ans;
    }
};