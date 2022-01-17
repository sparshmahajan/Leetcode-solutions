class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int words = 0,i=0;
        while(s[i]!=0){
            if(s[i]==' ') words++;
            i++;
        }
        if(words != pattern.length()-1) return false;
        unordered_map <char,string> mp1;
        unordered_map <string,char> mp2;
        vector <string> v;
        string s1="";
        for(i=0;s[i];i++){
            if(s[i]!=' ')
                s1 += s[i];
            else{
                v.push_back(s1);
                s1="";
            }
        }
        v.push_back(s1);
        for(i=0;pattern[i];i++){
            if(mp1.find(pattern[i])==mp1.end() && mp2.find(v[i])==mp2.end()){
                mp1[pattern[i]]=v[i];
                mp2[v[i]] = pattern[i];
            }
            else if(mp1.find(pattern[i])!=mp1.end() && mp2.find(v[i])!=mp2.end()){
                if(mp1[pattern[i]] != v[i]) return false;
                if(mp2[v[i]] != pattern[i]) return false;
            }
            else return false;
        }
        return true;
    }
};