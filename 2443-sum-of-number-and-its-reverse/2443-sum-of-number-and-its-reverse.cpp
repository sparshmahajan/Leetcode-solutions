class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 0)
            return true;
        int newNum,x,rem;
        for(int i=1;i<= num ;i++){
            x = i;
            newNum = 0;
            while(x > 0){
                rem = x % 10;
                x /= 10;
                newNum = (newNum * 10) + rem;
            }
            if(i + newNum == num)
                return true;
        }
        return false;
    }
};