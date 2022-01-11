class Solution {
public:
    int lengthOfLastWord(string s) {
        int len =0,i;
        for(i=0;i<s.length();i++){
            if(s[i]==32 and !(s[i+1]==32 or s[i+1]==0)){
                cout<<len<<" ";
                len=0;
            }
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')) len++;
        }
        return len;
    }
};