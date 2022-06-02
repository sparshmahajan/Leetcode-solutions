class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        map<int,int> sums;
        for(int i=0;i<nums.size()-2;i++){
            int start = i+1, end = nums.size()-1,sum;
            while(start < end){
             sum = nums[start] + nums[end] + nums[i];
             sums[abs(sum - target)] = sum;
             if(sum > target) end--;
             else if(sum < target) start++;
             else{
                start++;
                end--;
             }
            }
        }        
        auto it = sums.begin();
        return it->second;
    }
};