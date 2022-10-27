class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 != 0)
            return {};
        
        long long res = num / 3;
        return {res-1,res,res+1};
    }
};