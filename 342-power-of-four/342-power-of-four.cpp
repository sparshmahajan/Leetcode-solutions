class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        long int i=4;
        while(i<=n){
            if(i==n) return true;
            i*=4;
        }
        return false;
    }
};