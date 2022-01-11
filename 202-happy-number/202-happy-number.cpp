class Solution {
public:
    bool isHappy(int n) {
        int i,rem,num;
        while(1){
            i=n;
            num = 0;
            while(i>0){
                rem = i%10;
                i/=10;
                num+= (rem*rem);
                }
            n=num;
            if(n==1) return true;
            if(n==89) return false;
        }  
        return false;
    }
};