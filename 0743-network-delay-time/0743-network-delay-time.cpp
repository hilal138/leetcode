class Solution {
public:
    vector<list<pair<int,int>>> graph;
    vector<int> time;

    void add_edge(int src, int dest, int weight){
        graph[src].push_back({dest, weight}); 
    }

    int networkDelayTime(vector<vector<int>>& arr, int n, int src) {

        graph.resize(n + 1);
        
        for(int i=0;i<arr.size();i++){
            add_edge(arr[i][0], arr[i][1], arr[i][2]);
        }

        time.resize(n+1 ,INT_MAX);
        
        time[src] = 0; 
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(distance > time[node]) continue;
            
            for(auto  edge : graph[node]){
                int neighbor = edge.first;
                int weight = edge.second;
                
                if(time[node] + weight < time[neighbor]){
                    time[neighbor] = time[node] + weight;
                    pq.push({time[neighbor], neighbor});
                }
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