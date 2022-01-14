class Solution {
public:
    int myAtoi(string s) {
        long int num=0;
        int i=0,sign=0,plus=0,pre=1;
        while(s[i]==' ') i++;
        if(s[i]=='-'){
            sign=1;
            i++;
        }
        if(s[i]=='+'){
            plus=1;
            i++;
        }
        if(plus and sign) return 0;
        while(i<s.length() and (s[i]>='0' and s[i]<='9')){
            num = (num*10)+(s[i]-'0');
            if(num>=INT_MAX) {
                if(num == INT_MAX) pre = 0;
                num=INT_MAX;
                break;
            }
            i++;
        }
        if(sign == 1){
            if(num == INT_MAX and pre) num+=1;
            num*=-1;
        }
        
        return int(num);
    }
};