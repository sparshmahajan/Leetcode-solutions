class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans=0;
        for(int i=1; n>0 ; i*=2){
            ans += (i* !(n%2));
            n/=2;
        }
        return ans;
    }
};