class Solution {
public:
    bool detectCapitalUse(string word) {
        int all = 0,first=0,flag = 1;
        if(word[0]>='A' and word[0]<='Z'){
            first=1;
        }
        if(!first){
            for(int i=1;i<word.length();i++){
                if(!(word[i]>='a' and word[i]<='z'))
                    flag = 0;   
             }
        }
        else if(first and (word[1]>='a' and word[1]<='z')){
            for(int i=1;i<word.length();i++){
            if(!(word[i]>='a' and word[i]<='z'))
                flag = 0;   
          }  
        }
        else if(first){
          for(int i=1;i<word.length();i++){
            if(!(word[i]>='A' and word[i]<='Z'))
                flag = 0;   
          }  
        }
        
        return flag;
    }
};