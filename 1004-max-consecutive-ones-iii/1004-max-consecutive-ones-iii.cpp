class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int n = nums.size();
        int l=0;
        int r=0;
        int len=0;
        while(r<n){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }

        return len;
    }
};