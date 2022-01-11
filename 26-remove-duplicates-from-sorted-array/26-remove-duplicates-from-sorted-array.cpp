class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,i,n=nums.size();
        for(i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                nums[i-1]=101;
                
            }
        }
        sort(nums.begin(),nums.end());
        for(int c : nums){
            if(c==101) return k;
            k++;
        }
        return k;
    }
};