class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector <int> freq(26,0);
        for(char s : sentence){
            freq[s-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i] == 0)
                return false;
        }
        return true;
    }
};