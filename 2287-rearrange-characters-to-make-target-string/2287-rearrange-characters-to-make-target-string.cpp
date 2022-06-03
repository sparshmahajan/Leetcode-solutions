class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map <char,int> freqS;
        map <char,int> freqT;
        for(int i=0;i<s.length();i++){
            freqS[s[i]]++;
        }
        for(int i=0;i<target.length();i++){
            freqT[target[i]]++;
        }
        int res= INT_MAX;
        for(int i=0;i<target.length();i++){
                res = min(res,freqS[target[i]]/freqT[target[i]]);
        }
        return res;
    }
};