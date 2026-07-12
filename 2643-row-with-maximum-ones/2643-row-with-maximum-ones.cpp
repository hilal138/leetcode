class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int m =arr.size();
        int n =arr[0].size();
        int currCount=0;
        int maxCount=0;
        int idx=-1;
        for(int i=0;i<m;i++){
            currCount=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) currCount++;
                if(currCount>maxCount){
                    maxCount=currCount;
                    idx=i;
                }
            }
        }
        if(idx==-1) return {0,0};
        else return {idx,maxCount};
    }
};