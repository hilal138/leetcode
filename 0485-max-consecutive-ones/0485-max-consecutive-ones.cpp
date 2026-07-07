class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int currcount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) {
                currcount++;
                count=max(count,currcount);
                
            }
            else currcount=0;
        }

        return count;
    }
};