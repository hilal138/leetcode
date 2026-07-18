class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        if(x==1)return 1;
        int lo=1;
        int hgh=x;
        long long ans;
        while(lo<=hgh){
            long long mid =lo +(hgh-lo)/2;

            
            if(mid*mid==x )return mid;
            else if(mid*mid>x) hgh=mid-1;
            else lo=mid+1;
        }
        return hgh;
    }
};