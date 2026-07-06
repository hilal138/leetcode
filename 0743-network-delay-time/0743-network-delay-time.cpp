class Solution {
public:

    vector<int> time;

    int networkDelayTime(vector<vector<int>>& arr, int n, int src) {
        time.resize(n+1 ,INT_MAX);
        time[src] = 0; 

        for(int i=1;i<=n-1;i++){
            for(int j=0;j<arr.size();j++){
                int u = arr[j][0];
                int v = arr[j][1];
                int wt = arr[j][2];
                if(time[u]!=INT_MAX and time[u]+wt < time[v] ) time[v]=time[u]+wt;
            }
        }
        
        
        int Max=INT_MIN;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX) return -1;
            else Max= max(Max,time[i]);
        }

        return Max;
    }
};