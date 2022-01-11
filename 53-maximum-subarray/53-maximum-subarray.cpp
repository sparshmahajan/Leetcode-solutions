class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum = 0,i,msum=0,neg=1;
        for(i=0;i<nums.size();i++){
            if(nums[i]>0) neg=0;
        }
        if(neg) return *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
           if(csum < 0) csum = 0;
            if(csum > msum) msum = csum;
        }
        return msum;
    }
};