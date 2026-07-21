class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            q.push(i);
        }
        while(q.size()>0 and freq[s[q.front()]-'a']>1) q.pop();
        if(q.size()==0) return -1;
        return q.front();
    }
};