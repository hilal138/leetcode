class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum=0;
        int rsum=0;
        int maxsum=0;
        for(int i=0;i<k;i++){
            lsum+=arr[i];
        }
        maxsum=lsum;
        int rightidx=arr.size()-1;
        for(int i = k-1 ;i>=0;i--){
            lsum-=arr[i];
            rsum+=arr[rightidx];
            rightidx--;
            maxsum=max(maxsum,lsum+rsum);
        }

        return maxsum;
    }
};