class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(),i;
        unordered_map<int,int> mp;
        for(i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count = 0;
        if(k!=0){
            for(auto it=mp.begin();it!=mp.end();it++){
                if(mp.find(it->first+k) != mp.end())
                    count++;
            }
        }
        else{
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second > 1)
                    count++;
            }
        }
        return count;
    }
};