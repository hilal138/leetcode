class Solution {
public:
    int countNegatives(vector<vector<int>>& arr) {
        int m = arr.size();
        int n =arr[0].size();
        int i=0;
        int j=n-1;
        int count=0;
        while(i<m and j >=0){

            if(arr[i][j]<0){
                count+=m-i;
                j--;
            }
            else{
                i++;
            }
        }
        return count;
    }
};