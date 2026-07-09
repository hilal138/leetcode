class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int lo=0;
        int hgh=n-1;
        int idx=-1;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
            if(arr[mid]==target){
                 idx=mid;
                 break;
            }
            else if(arr[mid]<target) lo=mid+1;
            else hgh=mid-1;

        }
        return idx;
    }
};