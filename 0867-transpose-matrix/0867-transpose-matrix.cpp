class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& arr) {
        int m = arr.size();
        int n =arr[0].size();
        vector<vector<int>>v;
        v.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j]=arr[j][i];
            }
        }
        return v;
    }
};