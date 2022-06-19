class Solution {
public:
    void solve(int idx,string& digits,string s,vector<string>& ans,vector<string>& mp){
        if(idx == 0){
            ans.push_back(s);
            return;
        }

        int index = digits[idx-1] - '2';
        for(int i=0;i<mp[index].size();i++){
            string t = mp[index];
            solve(idx-1,digits,t[i]+s,ans,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        vector<string> mp = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits.size(),digits,"",ans,mp);
        return ans;
    }
};