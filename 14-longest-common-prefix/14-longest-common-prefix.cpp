class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (int i = 0; i < strs[0].size(); ++i){
            char ch = strs[0][i];
            for (string word: strs){
                if (i == word.size() || word[i] != ch) return ans;
            }
            ans += ch;
        }
        return ans;

    }
};