class Solution {
public:
    int mySqrt(int x) {
        long long start = 0,end = x,mid,ans;
        while(start<=end){
            mid = (start+end)/2;
            if((mid*mid) == x){
                return mid;
            }
            else if ((mid*mid)>x){
                end = mid - 1;
                ans = end;
            }
            else
                start = mid + 1;
        }
       // cout<<ans;
        return ans;
    }
};