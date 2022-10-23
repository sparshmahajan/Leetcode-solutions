class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector <int> res;
        map <int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(int i=0;i<n;i++){
            if(mp[nums[i]] == 2){
                res.push_back(nums[i]);
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(mp[i+1] == 0){
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};