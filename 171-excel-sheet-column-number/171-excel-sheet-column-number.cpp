class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=0,i=0;
        while(columnTitle[i]!=0){
            n = (n*26) + (columnTitle[i]-'A'+1);
            i++;
        }
        return n;
    }
};