class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber>0){
            columnNumber--;
            s += ('A' + (columnNumber%26));
            columnNumber/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};