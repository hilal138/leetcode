class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hgh=n-1;
        vector<int>v(2,-1);
        while(lo<=hgh){  // left occurance
            int mid = lo + (hgh-lo)/2;
            if(nums[mid]==target){
                v[0]=mid;
                hgh=mid-1;
            }
            else if (nums[mid]> target) hgh=mid-1;
            else lo=mid+1;
        }
         lo=0;
         hgh=n-1;
        while(lo<=hgh){  // right occurance
            int mid = lo + (hgh-lo)/2;
            if(nums[mid]==target){
                v[1]=mid;
                lo=mid+1;
            }
            else if (nums[mid]> target) hgh=mid-1;
            else lo=mid+1;
        }
        return v;
    }
};