class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        int n = arr.size();
        vector<int>nge(n);
        stack<int>st;
        nge[n-1]=-1;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 and st.top()<arr[i]) st.pop();
            if(st.size()==0) nge[i]=-1;
            else nge[i]=st.top();
            st.push(arr[i]);
        }
        for(int i=0;i<nums1.size();i++){
            int idx=-1;
            for(int j=0;j<n;j++){
                if(nums1[i]==arr[j]){
                    idx=j;
                    nums1[i]=nge[j];
                    break;
                }
            }
        }
        return nums1;

    }
};