class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int len=0;
        int curr=0;
        while(r<s.length()){
            if(mp.find(s[r])==mp.end()){
                mp[s[r]]=r;

            }
            else {
                l = max(l, mp[s[r]] + 1);
                mp[s[r]]=r;
            }
            curr=r-l+1;
            r++;
            len=max(curr,len);
        }

        return len;
    }
};