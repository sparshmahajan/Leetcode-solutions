class Solution {
public:
    bool isPalindrome(int start,int end,string s){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    void solve(int idx,string s,vector <string>& palindromes,vector <vector<string>>& ans){
        if(idx == s.size()){
            ans.push_back(palindromes);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(idx,i,s)){
                palindromes.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,palindromes,ans);
                palindromes.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector <string> palindromes;
        solve(0,s,palindromes,ans);
        return ans;
    }
};