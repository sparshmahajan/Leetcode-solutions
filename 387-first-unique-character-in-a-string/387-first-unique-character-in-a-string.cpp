class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> v(26,0);
        int i;
        for(i=0;i<s.length();i++){
            v[s[i]-97]++;
        }
        for(i=0;i<s.length();i++){
            if(v[s[i]-97]==1) return i;
        }
        i=-1;
        return i;
    }
};