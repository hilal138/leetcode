class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int a=0;
        for(auto ele : nums) a=a^ele;

        return a;
    }
};