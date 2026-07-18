class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        long long lo = 1;
        long long hgh=num/2;
        while(lo<=hgh){
            long long mid = lo + (hgh-lo)/2;
            if(mid*mid==num){
                return true;
            }
            else if(mid*mid>num)hgh=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};