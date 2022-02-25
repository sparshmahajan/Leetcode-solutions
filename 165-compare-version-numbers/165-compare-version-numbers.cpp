class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(!version1.empty() and !version2.empty()){
            int n1=stoi(version1);
            int n2=stoi(version2);
            if(n1 > n2)
                return 1;
            else if (n1 < n2)
                return -1;
            while(version1[0] != '.' and version1[0]!=0)
                version1.erase(version1.begin()+0);
            if(version1[0]=='.')
            version1.erase(version1.begin()+0);
           // cout<<version1<<endl;
            while(version2[0] != '.' and version2[0]!=0)
                version2.erase(version2.begin()+0);
            if(version2[0]=='.')
            version2.erase(version2.begin()+0);
           // cout<<version2<<endl;

        }
        while(!version1.empty()){
            int n1=stoi(version1);
            if(n1 != 0)
                return 1;
            while(version1[0] != '.' and version1[0]!=0)
                version1.erase(version1.begin()+0);
            if(version1[0]=='.')
            version1.erase(version1.begin()+0);
        }
        while(!version2.empty()){
            int n2=stoi(version2);
            if(n2 != 0)
                return -1;
            while(version2[0] != '.' and version2[0]!=0)
                version2.erase(version2.begin()+0);
            if(version2[0]=='.')
            version2.erase(version2.begin()+0);
        }
        return 0;
    }
};