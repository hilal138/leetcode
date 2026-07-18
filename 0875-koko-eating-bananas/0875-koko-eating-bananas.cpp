class Solution {
public:
    long long helper(vector<int>&arr, int mid){
        long long  time=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid) time+=1;
            else time+= (arr[i]+mid-1)/mid;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = INT_MIN;
        for(auto ele : arr) if(ele>n)n=ele;
        int lo=1;
        int hgh=n;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
            long long  time= helper(arr,mid);
            if(time<=h) hgh=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};