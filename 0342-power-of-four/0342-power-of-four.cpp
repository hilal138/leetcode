class Solution {
public:
    bool pow2(int n){
        return n>0 and  (n & n-1)==0;
    }
    bool perfectsqr(int n){
        long long x = sqrt(n);
        if(x*x==n) return true;
        return false;
    }
    bool isPowerOfFour(int n) {
        return pow2(n) and perfectsqr(n);
    }
};