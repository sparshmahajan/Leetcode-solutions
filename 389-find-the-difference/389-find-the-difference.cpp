class Solution {
public:
    char findTheDifference(string s, string t) {
        vector <int> ans(26,0);
        int i;
        for(i=0;i<s.length();i++){
            ans[s[i]-97]++;
        }
        for(i=0;i<t.length();i++){
            ans[t[i]-97]--;
        }
        char ch;
        for(i=0;i<ans.size();i++){
            if(ans[i]!=0) return ch = i+97; 
        }
        return ch;
    }
};