class Solution {
public:
    bool is_unique(string& s){
        vector <int> mp(26,0);
        for(char c : s){
            mp[c - 'a']++;
            if(mp[c - 'a'] > 1)
                return false;
        }
        return true;
    }
    
    int helper(int i,int maxL,vector<string>& arr,string s){
        if(!is_unique(s))
            return INT_MIN;
        
        if(i >= arr.size()){
            if(maxL < s.size())
                return s.size();
            return maxL;
        }
        
        maxL = max(helper(i+1,maxL,arr,s), helper(i+1,maxL,arr,s + arr[i]));
        
        return maxL;
    }
    
    int maxLength(vector<string>& arr) {
        return helper(0,0,arr,"");
    }
};