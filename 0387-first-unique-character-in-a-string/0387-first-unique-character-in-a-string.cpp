class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        int idx=-1;
        for(int i=0;i<n;i++){
            int j=0;
            while(j<n){
                if(i==j){
                    j++;
                    continue;
                }
                if(s[i]!=s[j]) {
                    j++;
                }
                else break;
            }
            if(j==n){
                idx=i;
                break;
            }
        }
        return idx;
    }
};