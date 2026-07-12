class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo=0;
        int hgh =n-1;
        while(lo<hgh){
            int mid =lo +(hgh-lo)/2;
            if(mid%2!=0) mid--;
            if(nums[mid]==nums[mid+1])lo=mid+2;
            else hgh=mid;
        }
    return nums[lo];
    }
};