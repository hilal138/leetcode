class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto ele : nums) mp[ele]++;

        for(auto ele : mp){
            if(ele.second > n/3)ans.push_back(ele.first);
        }

        return ans;
    }
};