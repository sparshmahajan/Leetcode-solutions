class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = s.length();
        int t1 = t.length();
        int j=0;
        for(int i=0;i<t1;i++){
            if(s[j] == t[i])
                j++;
        }
        return j == s1;
    }
};