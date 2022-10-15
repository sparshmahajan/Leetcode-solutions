class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> arr,result;
        arr = nums;
        sort(arr.begin(),arr.end());
        int start = 0 , end = nums.size()-1,sum;
        while(start < end){
            sum = arr[start] + arr[end];
            if(sum == target)
                break;
            else if( sum > target)
                end--;
            else
                start++;
        }
        // int i;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == arr[start]){
                result.push_back(i);
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i != result[0] && nums[i] == arr[end]){
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};