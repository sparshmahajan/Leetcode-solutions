class Solution {
public:
    bool isPalindrome(int i,int j,string s){
        while(i<j){
           if(s[i++]!=s[j--]) 
               return false; 
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(isPalindrome(i+1,j,s) or isPalindrome(i,j-1,s)) return true;
                return false;
            }
        }
        return true;
    }
};