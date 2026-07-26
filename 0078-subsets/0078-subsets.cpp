class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<pow(2,n);i++){
            vector<int>v;
            long long x =i;
            for(int j=0;j<n;j++){
                if(x%2!=0)v.push_back(nums[j]);
                x=x>>1;
            }
            ans.push_back(v);
        }

        return ans;
    }
};