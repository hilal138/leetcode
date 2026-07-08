class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(auto ele : nums) if(ele==0) count++;
        vector<int>helper;
        helper=nums;
        for(int i=0;i<n;i++){
            nums[i]=0;
        }
        int i=0;
        int j=0;
        while(i<n){
            if(helper[i]==0) i++;
            else{
                nums[j]=helper[i];
                i++;
                j++;
            }
        }
        return;
    }
};