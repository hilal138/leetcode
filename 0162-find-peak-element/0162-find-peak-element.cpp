class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak lies on the right
                lo = mid + 1;
            } else {
                // Peak is at mid or on the left
                hi = mid;
            }
        }

        return lo;
    }
};