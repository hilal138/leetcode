class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans = "";
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(st.empty() or st.top()!=s[i])st.push(s[i]);
            else st.pop();
        }
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};