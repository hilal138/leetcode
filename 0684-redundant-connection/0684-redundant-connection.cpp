class Solution {
public:
    vector<int>parent;
    vector<int>size;
    vector<int>ans;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int a , int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]<=size[b]){
            parent[a]=b;
            size[b]+=size[a];
        }
        else{
            size[b]+=size[a];
            parent[b]=a;
          }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        
        parent.resize(n+1,0);
        ans.resize(2,-1);
        size.resize(n+1,1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(find(u) == find(v)){
                ans[0]=u;
                ans[1]=v;
            }
            Union(u,v);
        }
        return ans ;
    }
};