class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int maj_ele,count=0;
        for(int i : nums){
            if(count==0)
                maj_ele = i;
            if(maj_ele == i)
                count++;
            else
                count--;
        }
        return maj_ele;
    }
};