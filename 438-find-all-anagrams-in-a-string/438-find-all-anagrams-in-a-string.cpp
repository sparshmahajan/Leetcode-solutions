class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        vector <int> freq(26,0) ,slid(26,0);
        int slen= s.length(),plen = p.length();
        if(plen > slen) 
            return ans;
        int left=0,right=0;
        while(right < plen){
            freq[p[right] - 'a']++;
            slid[s[right++] - 'a']++;
        }
        --right;
        while(right < slen){
           if(freq == slid)
               ans.push_back(left);
           right++;
           if(right!=slen)
               slid[s[right]-'a']++;
           slid[s[left]-'a']--;
           left++;
        }
        return ans;
    }
};