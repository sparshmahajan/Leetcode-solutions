class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector <int> v(26,0);
        int i;
        for(i=0;i<s.length();i++){
            v[s[i]-97]++;
        }
        for(i=0;i<t.length();i++){
            v[t[i]-97]--;
        }
        for(i=0;i<26;i++){
            if(v[i]!=0) return false;
        }
        return true;
    }
};