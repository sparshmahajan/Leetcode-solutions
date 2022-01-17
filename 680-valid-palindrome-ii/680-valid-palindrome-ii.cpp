class Solution {
public:
    bool validPalindrome(string s) {
        int i=0, count1=0,count2=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                i++;
                count1++;
            }
        }
        i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                j--;
                count2++;
            }
        }
        if(count1==1 or count2==1)
            return true;
        if(count1==0 or count2==0) 
            return true;
        return false;
    }
};