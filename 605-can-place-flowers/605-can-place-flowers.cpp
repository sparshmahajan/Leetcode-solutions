class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int len = flowerbed.size();
        if(len == 1 and !flowerbed[0]) 
            return n==1;
        for(int i=flowerbed[0];i<len;i++){
            if(i==0){
                if(!flowerbed[i] and !flowerbed[i+1]){
                    n--;
                    flowerbed[i]=1;
                }
            }
            else if(i==len-1){
                if(!flowerbed[i-1] and !flowerbed[i]){
                    flowerbed[i]=1;
                    n--;
                }
            }
            else{
                if(!flowerbed[i-1] and !flowerbed[i] and !flowerbed[i+1]){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};