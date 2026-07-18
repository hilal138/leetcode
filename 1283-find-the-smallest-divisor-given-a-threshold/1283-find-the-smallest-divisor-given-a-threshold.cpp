class Solution {
public:
    int helper(vector<int>&arr, int mid){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+= (arr[i]+mid - 1)/ mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int target) {
        int hgh = INT_MIN;
        for(auto ele : nums) if(ele>hgh) hgh=ele;
        int lo=1;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
            int sum = helper(nums,mid);
            if(sum<=target) hgh=mid-1;
            else lo=mid+1;
        }

        return lo;
    }
};