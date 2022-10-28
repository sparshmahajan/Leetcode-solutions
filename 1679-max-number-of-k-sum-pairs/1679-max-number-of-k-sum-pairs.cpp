class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0;
        int start = 0 , end = n-1;
        while(start < end){
            if(nums[start] + nums[end] == k){
                count++;
                start++;
                end--;
            }
            
            else if(nums[start] + nums[end] > k)
                end--;
            else
                start++;
        }
        return count;
    }
};