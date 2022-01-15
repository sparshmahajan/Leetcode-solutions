class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size()==0) return 0;
        int count=1,i,n=nums.size();
        for(i=1;i<n;i++){
            if(nums[i-1] != nums[i]){
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};