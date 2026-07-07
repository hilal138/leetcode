class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int target) {
        vector<vector<int>>dist;
        dist.resize(n,vector<int>(n,INT_MAX));

        // filling givin initial weights
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            dist[u][v]=w;
            dist[v][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==k or j==k)continue;
                    if(dist[i][k]!=INT_MAX and dist[k][j]!= INT_MAX){
                         dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int minCount=INT_MAX;
        int minCity=-1;

        for(int i=0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j]<=target) count++;
            }
            if(count<=minCount){
                minCount=count;
                minCity=i;
            }
        }
        return minCity;
    }
};