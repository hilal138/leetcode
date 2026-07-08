class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int low=0;
        int mid=0;
        int hgh=n-1;
        while(mid<=hgh){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            } 
            else if (nums[mid]==2){
                 swap(nums[mid],nums[hgh]);
                 hgh--;
            }
            else mid++;
        }

        return;
    }
};