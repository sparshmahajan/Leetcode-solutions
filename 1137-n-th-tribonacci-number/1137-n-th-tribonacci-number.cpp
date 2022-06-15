class Solution {
public:
    int tribonacci(int n) {
        if(n < 3)
            return n == 2 ? 1 : n;
        int prev3 = 0 , prev2 = 1 , prev = 1,curr;
        
        for(int i=3;i<=n;i++){
            curr = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};