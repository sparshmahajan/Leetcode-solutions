class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v,result;
        v = nums;
        int start = 0, end = nums.size()-1,sum;
        sort(v.begin(),v.end());
        while(start < end){
            sum = v[start] + v[end];
            if(sum > target) end--;
            else if(sum < target) start++;
            else{
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == v[start]){
                result.push_back(i);
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == v[end] && i!= result[0]){
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};