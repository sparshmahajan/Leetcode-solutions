class Solution {
public:
    string addStrings(string num1, string num2) {
        string largerNum=num1.size()>=num2.size()?num1:num2;
        string smallerNum=num1.size()<num2.size()?num1:num2;
        int bitsDiff=largerNum.size()-smallerNum.size();
        while(bitsDiff!=0){
            smallerNum='0'+smallerNum;
            bitsDiff--;
        }        
        int carry=0;
        string result;
        for(int i=smallerNum.size()-1;i>=0;i--){
            int num_1=largerNum[i]-'0';
            int num_2=smallerNum[i]-'0';
            int sum=carry+num_1+num_2;
            if(sum>9){
                carry=1;
                result=(to_string(sum%10))+result;
            }
            else{
                carry=0;
                result=to_string(sum)+result;
            }
        }
        if(carry>0)result=to_string(carry)+result;
        return result;
    }
};