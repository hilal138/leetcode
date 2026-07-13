class Solution {
public:
    bool findRotation(vector<vector<int>>& arr, vector<vector<int>>& target) {
        int n =arr.size();
        int turn=0;
        while(turn<4){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(arr[i][j],arr[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                reverse(arr[i].begin(),arr[i].end());
            }
            if(arr==target) return true;
            else turn++;
        }
        return false;
    }
};