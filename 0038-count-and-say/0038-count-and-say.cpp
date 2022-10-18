class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        string str = "11";
        string temp = "";
        int count;
        for(int i=3;i<=n;i++){
            temp = "";
            count = 1;
            str += '&';
            for(int j=1;j<str.size();j++){
                if(str[j-1] != str[j]){
                    temp += to_string(count);
                    temp += str[j-1];
                    count = 1;
                } else
                    count++;
            }
            str = temp;
        }
        return str;
    }
};