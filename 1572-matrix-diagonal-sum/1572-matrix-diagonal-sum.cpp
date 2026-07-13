class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n==1) return arr[0][0];
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=arr[i][i];
        }
        int i=0;
        int j=n-1;
        while(i<n and j >=0){
            sum+=arr[i][j];
            i++;
            j--;
        }
        if(n%2==0) return sum;
        else return sum-arr[n/2][n/2];
    }
};