class Solution {
public:
    string reverseVowels(string s) {
        vector <int> idx;
        int i;
        for(i =0;s[i]!=0;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
                idx.push_back(i);
        }
        int j=idx.size()-1;
    
        for(i=0;i<j;i++,j--){
            swap(s[idx[i]],s[idx[j]]);
        }
        return s;
    }
};