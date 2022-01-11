class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums[i]=999;
            }
        }
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++){
            if(nums[i]==999) return i;
        }
        return i;
    }
};