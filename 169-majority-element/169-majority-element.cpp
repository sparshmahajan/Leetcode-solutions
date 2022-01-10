class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_idx=0,count = 1 ,i;
        for(i=1;i<nums.size();i++){
            if(nums[maj_idx] == nums[i]) count++;
            else{
                count--;
                if(count == 0){
                    count = 1;
                    maj_idx = i;
                }
            }
        }
        return nums[maj_idx];
    }
};