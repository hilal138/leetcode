class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n =arr.size();
        int lo=0;
        int hgh=n-1;
        int idx=-1;
        int missing=0;
        while(lo<=hgh){
            int mid = lo +(hgh-lo)/2;
            missing=arr[mid]-(mid+1);
            if(missing>=k){
                idx=mid;
                hgh=mid-1;
            }
            else lo=mid+1;
        }
        
        return lo+k;
    }
};