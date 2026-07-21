class Solution {
public:
    int firstUniqChar(string s) {
        int n= s.length();
        int idx=-1;
        unordered_map<char,int>mp;
        for(auto ele : s) mp[ele]++;
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1){
                idx=i;
                break;
            }
        }
        return idx;

    }
};