class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        int n =points.size();
        vector<int>visited;
        visited.resize(n,0);
        int sum=0;

        pq.push({0,0,-1});  // weight,node, parent
        
        while(pq.size()>0){
            auto [weight, node, parent] = pq.top();
            pq.pop();
            if (visited[node] == 1) continue;
            visited[node]=1;
            sum+=weight;

            for(int i=0;i<n;i++){
                if(i==node or i==parent) continue;
                if(visited[i]==1) continue;
                int x1=points[node][0];
                int y1=points[node][1];
                int x2=points[i][0];
                int y2=points[i][1];
                int dist= abs(x2-x1) + abs(y2-y1);
                pq.push({dist,i,node});
            }
        }
        return sum;
    }
};