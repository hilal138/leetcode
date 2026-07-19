class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (auto ele : s){
            if(ele=='{' or ele =='[' or ele == '(') st.push(ele);
            if(ele==']'){
                if(st.empty() or st.top()!='[' ) return false;
                else st.pop();
            }
            if(ele=='}'){
                if(st.empty() or st.top()!='{' ) return false;
                else st.pop();
            }
            if(ele==')'){
                if(st.empty() or st.top()!='(' ) return false;
                else st.pop();
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};