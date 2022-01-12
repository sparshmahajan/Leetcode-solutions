class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ans;
        if(nums.size() == 0) return ans;
        if(nums.size() == 1 ){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int i=1,j=0,count=0,n=nums.size();
        while(i<n and j<n){
            if(nums[i-1]+1 == nums[i]){
                count++;
            }
            else{
                if(count == 0) ans.push_back(to_string(nums[j]));
                else{
                    ans.push_back(to_string(nums[j]) + "->" + to_string(nums[j]+count));
                    count=0;
                }
                j=i;
            }
            i++;
        }
        if(j<n and count==0) ans.push_back(to_string(nums[j]));
        else{
           ans.push_back(to_string(nums[j]) + "->" + to_string(nums[j]+count)); 
        }
        return ans;
    }
};