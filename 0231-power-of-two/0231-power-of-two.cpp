class Solution {
public:
    bool isPowerOfTwo(int n) {
        int m=n/2;
        for(int i=0;i<=30;i++){
            if(1<<i==n) return true;
        }
        return false;
    }
};