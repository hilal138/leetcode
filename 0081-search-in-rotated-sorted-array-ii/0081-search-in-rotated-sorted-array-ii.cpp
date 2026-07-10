class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        bool flag =false;
        int lo=0;
        int hgh=n-1;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
            if(nums[mid]==target) return true;
            if (nums[lo] == nums[mid] && nums[mid] == nums[hgh]) {
                  lo++;
                  hgh--;
                  continue;
            }
            
            if(nums[lo]<=nums[mid]){
                if(target>=nums[lo] and target <= nums[mid]) hgh=mid-1;
                else lo =mid+1;
            }
            else {
                if(target>=nums[mid] and target <= nums[hgh]) lo=mid+1;
                else hgh=mid-1;
            }
        }
        return flag;
    }
};