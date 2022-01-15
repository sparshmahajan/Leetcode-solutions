class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> v;
    unordered_map<int,int> freq;
    for(int i=0;i<nums.size();i++){
            int s = target - nums[i];
            if(freq.find(s)!=freq.end()){
                v.push_back(i);
                v.push_back(freq[s]);      
            }
        freq[nums[i]] = i;
        }
        return v;
    }
};