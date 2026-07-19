class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int n = s.length();
        int i =0;
        int count=0;
        while(i<n){
            if(s[i]=='(' and count==0){
                i++;
                count++;
                continue;
            }
            if(s[i]==')' and count==1){
                count=0;
                i++;
                continue;
            }
            if(s[i]=='('){
                count++;
                ans+=s[i];
                i++;
            }
            if(s[i]==')'){
                count--;
                ans+=s[i];
                i++;
            }
        }

        return ans;

    }
};