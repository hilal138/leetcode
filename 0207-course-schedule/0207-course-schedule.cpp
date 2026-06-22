class Solution {
public:
    vector<list<int>>graph;
    vector<int>path;
    bool ans = true ;  //no cycle is there 
  
    void add_edge(int src, int des){
        graph[src].push_back(des);
        return;
    }

    void dfs(vector<int>&visited, int start){
        visited[start]=1;
        path[start]=1;

        for(auto ele : graph[start]){
            if(visited[ele]==0){
                dfs(visited,ele);
            }

            else if (visited[ele]== 1 and path[ele]==1){
                ans=false;  // there is cycle
            }
        }
        path[start]=0;
    }
    
    bool canFinish(int V, vector<vector<int>>& edges) {
        int e=edges.size();
       
        graph.resize(V);
       for(int i=0;i<e;i++){
           add_edge(edges[i][0],edges[i][1]);
       }
       
        path.resize(V,0);
       
        vector<int>visited;
        visited.resize(V,0);

       
       for(int i=0;i<V;i++){
           if(visited[i]==0) dfs(visited,i);
       }
       return ans;
    }
};