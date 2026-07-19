class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(auto ele : s){
            if(ele=='(') st.push(ele);
            else {
                if(st.size()==0) count++;
                else st.pop();
            }
        }
        return count+st.size();
    }
};