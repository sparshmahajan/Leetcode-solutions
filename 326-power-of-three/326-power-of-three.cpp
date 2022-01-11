class Solution {
public:
    bool isPowerOfThree(int n) {
        int t = 1162261467;
        return n > 0 and t % n == 0;
    }
};