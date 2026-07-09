class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n =arr.size();
        vector<int>ans(n);
        int j=0;
        int k=1;
        for(int i=0;i<n;i++){
            if (j < n-1 and arr[i]>0) {
                ans[j]=arr[i];
                j+=2;
            }
            else if (k<n and arr[i]<0){
                ans[k]=arr[i];
                k+=2;
            }
        }
        return ans;
    }
};