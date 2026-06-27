class Solution {
public:
    vector<list<pair<int,double>>> graph;
    vector<double> ans;

    void add_edge(int src, int dest, double prob){
        graph[src].push_back({dest, prob});
        graph[dest].push_back({src, prob});
    }

    double maxProbability(int n,vector<vector<int>>& edges,vector<double>& succProb, int start,int end) {

        graph.assign(n, {});
        ans.assign(n, 0.0);

        for(int i = 0; i < edges.size(); i++){
            add_edge(edges[i][0], edges[i][1], succProb[i]);
        }

        priority_queue<pair<double,int>> pq;

        ans[start] = 1.0;
        pq.push({1.0, start});

        while(!pq.empty()){
            auto [prob, node] = pq.top();
            pq.pop();

            if(prob < ans[node]) continue;

            for(auto &edge : graph[node]){
                int neighbor = edge.first;
                double edgeProb = edge.second;

                if(ans[node] * edgeProb > ans[neighbor]){
                    ans[neighbor] = ans[node] * edgeProb;
                    pq.push({ans[neighbor], neighbor});
                }
            }
        }

        return ans[end];
    }
};