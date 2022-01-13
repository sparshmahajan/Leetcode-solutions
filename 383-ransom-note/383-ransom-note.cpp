class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i;
        vector <int> v(26,0);
        for(i=0;i<ransomNote.length();i++){
            v[ransomNote[i]-97]++;
        }
        for(i=0;i<magazine.length();i++){
            v[magazine[i]-97]--;
        }
        for(i=0;i<v.size();i++){
            if(v[i]>0) return false;
        }
        return true;
    }
};