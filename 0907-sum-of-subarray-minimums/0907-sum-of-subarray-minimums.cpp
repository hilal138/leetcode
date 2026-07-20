class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
int n=arr.size();
        stack<int>st;
        int next[n];
        // next smaller idx elements array 
        next[n-1]=n;   // change
        st.push(n-1);  // change
        for(int i=n-2;i>=0;i--){
        while(st.size()>0 && arr[st.top()]>arr[i]) st.pop();
        if(st.size()==0) next[i]=n;
        else next[i]=st.top();
        st.push(i);
        }

        // previous index  greatest elements array
        int prev[n];
        stack<int>gt;
        prev[0]=-1;
        gt.push(0);
        for(int i=1;i<n;i++){
        while(gt.size()>0 && arr[gt.top()]>=arr[i]) gt.pop();
        if(gt.size()==0) prev[i]=-1;
        else prev[i]=gt.top();
        gt.push(i);
        }

        long long  sum=0;
        for(int i=0;i<n;i++){
            sum+= 1LL*(next[i]-i)*(i-prev[i])*arr[i];
        }

        return sum%1000000007;

    }
};