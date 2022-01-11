class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int i = digits.size()-1;
        for(i;i>=0;i--){
            if(i==0 and digits[i]==9){
                digits[i]=1;
                digits.push_back(0);
            }
            else{
                digits[i]+=1;
                if(digits[i]==10) digits[i]=0;
                else break;
            }
            
        }
        return digits;
    }
};