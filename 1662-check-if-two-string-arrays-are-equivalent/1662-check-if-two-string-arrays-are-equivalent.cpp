class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";
        for(string s : word1){
            for(char c : s){
                s1 += c;
            }
        }
        
        for(string s : word2){
            for(char c : s){
                s2 += c;
            }
        }
        
        return s1 == s2;
    }
};