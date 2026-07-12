class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
 int m = arr.size();
        int n =arr[0].size();
        int i=0;
        int j=n-1;
        while(i<m and j >=0){
            if(arr[i][j]==target){
                return true;
                break;
            }
            else if (arr[i][j]>target) j--;
            else i++;
        }
    return false;   
    }
};