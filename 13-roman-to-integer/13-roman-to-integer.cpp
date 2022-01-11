class Solution {
public:
    int romanToInt(string s) {
          int res = 0;
    map<char, int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    long long int n = s.size();
    for(long long int i=0; i<n; ++i)
    {
        char temp1 = s[i];
        
        if(i==0)
        {
            res = res+m[temp1];
        }
        else
        {
            char temp2 = s[i-1];
            if(m[temp1]>m[temp2])
            {
                res+=m[temp1]-2*m[temp2];
            }
            else
            {
                
                res+=m[temp1];
            }
        }
    }
    return res;
    }
};