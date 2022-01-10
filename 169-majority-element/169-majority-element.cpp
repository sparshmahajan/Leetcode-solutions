class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_ele=0,count = 0 ,i;
        for(i=0;i<nums.size();i++){
            if(count == 0) maj_ele = nums[i];
            if(maj_ele == nums[i]) count++;
            else count--;
        }
        return maj_ele;
    }
};