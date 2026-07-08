class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
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