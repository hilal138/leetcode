class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int Min=INT_MAX;
        int lo=0;
        int hgh=n-1;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
            if(nums[mid]>nums[hgh]){
                lo=mid+1;
                Min=min(nums[lo],Min);
            }
            else{
                hgh=mid-1;
                Min=min(nums[mid],Min);
            }
        }

        return Min;
    }
};