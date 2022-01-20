class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int t = *max_element(piles.begin(),piles.end());
        int i,sum =0,j=1;
        int mid,ans;
        while(j<t){
             sum = 0;
           for(i=0;i<piles.size();i++){
                mid = j + (t-j)/2; 
                if(piles[i]%mid == 0) 
                     sum +=  (piles[i]/mid);
                else
                     sum +=  (piles[i]/mid)+1;
                if(sum > h and i == piles.size()-1){  
                  j = mid+1;
                }
                else if(sum <= h and i == piles.size()-1) {
                  t = mid; 
                }
           }
        }
        return j;
    }
};
