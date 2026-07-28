class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        int l=0;
        int r=0;
        int len=0;
        while(r<n){
            mp[arr[r]]++;

            if(mp.size()>2){
                while(mp.size()>2){
                    
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0) mp.erase(arr[l]);
                    l++;
                }
            }
            len=max(len,r-l+1);
            r++;
        }

        return len;
    }
};