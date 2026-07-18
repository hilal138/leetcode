class Solution {
public:
    double helper(vector<int>&arr, int mid){
        double sum=0;
        for(int i=0;i<arr.size()-1;i++){
            sum+= (arr[i]+mid - 1)/ mid;
        }
        sum+=1.0*arr[arr.size()-1]/mid;
        return sum;
    }
    int minSpeedOnTime(vector<int>& nums, double target) {
        int hgh = 10000000;
        int lo=1;
        int ans =INT_MAX;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
            double sum = helper(nums,mid);
            if(sum>target) lo=mid+1;
            else {
                ans=min(ans,mid);
                hgh=mid-1;
            }
        }
        if(ans==INT_MAX) return -1;
       else  return ans;
    }
};