class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codes;
        int i=0,n=s.length();
        for(i=0;i<=n-k;i++){
            codes.insert(s.substr(i,k));
        }
        return codes.size() == pow(2,k);
    }
};