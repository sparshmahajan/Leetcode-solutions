class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3) return true;
        if(n&1) return true;
        n/=2;
        if(n&1) return true;
        return false;
    }
};