class Solution {
public:
    string addBinary(string str1, string str2) {
        int i = str1.size() - 1 ;
        int j = str2.size() - 1 ;
        int carry = 0; 
        string res = "";
        while(i >= 0 || j >= 0 || carry){
            int a = 0;
            int b = 0;
            if(i >= 0)
                if(str1[i] - '0')
                    a = 1;
            if(j >= 0)
                if(str2[j] - '0')
                    b = 1;
            int c  = a + b + carry ;
            carry = c>1 ? 1 : 0;
            c = c%2==0 ? 0 : 1;
            res = to_string(c)+res;
            i--;
            j--;
        }
        return res;
    }
};