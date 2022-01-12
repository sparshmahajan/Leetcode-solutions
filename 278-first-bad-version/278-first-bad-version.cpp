// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return recursiveSearch(0,n);
    }
    int recursiveSearch(int start , int end){
        if(isBadVersion(end-1) == false) return end;
        int mid = start + (end-start)/2;
        if(isBadVersion(mid)==true){
            if(isBadVersion(mid-1)==false) return mid;
            else return recursiveSearch(start,mid-1);
        }
        else return recursiveSearch(mid+1,end);
    }
};