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
    
    void helper(int i,int& maxL,vector<string>& arr,string s){
        if(!is_unique(s))
            return;
        
        if(i >= arr.size()){
            if(maxL < s.size())
                maxL = s.size();
            return;
        }
        
        helper(i+1,maxL,arr,s);
        helper(i+1,maxL,arr,s + arr[i]);
        
        return;
    }
    
    int maxLength(vector<string>& arr) {
        int maxL = 0;
        helper(0,maxL,arr,"");
        return maxL;
    }
};