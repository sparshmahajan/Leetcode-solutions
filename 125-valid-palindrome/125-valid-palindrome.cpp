class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==1) return true;
        string s1="";
        int i=0,j=0;
        while(s[i]!=0){
            if(s[i]>='a' and s[i]<='z') s1+= s[i];
            else if(s[i]>='A' and s[i]<='Z') s1+= s[i]+32;
            else if(s[i]>='0' and s[i]<='9') s1+= s[i];
            i++;
            
        }
        j=s1.size()-1;
        for(i=0;i<=j;i++){
            if(s1[i]!=s1[j--]) return false;
        }
        return true;
    }
};