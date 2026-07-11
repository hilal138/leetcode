class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Find the pivot
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i])
                idx = i;
        }

        // If no pivot exists, reverse the whole array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the first element greater than nums[idx] from the right
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Reverse the suffix
        reverse(nums.begin() + idx + 1, nums.end());
    }
};