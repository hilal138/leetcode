class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    int ans = arr.size();

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
    }
};