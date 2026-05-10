class Solution {
    private:
    bool isCycleDFS(vector<vector<int>> &adj, vector<bool> &vis, int V, int n,int i, int parent){
        vis[i]=true;
        for(auto &it: adj[i]){ // can also write (auto it: adj[i]
            if(it==parent)
            continue;
            if(vis[it])
            return true;
            if(isCycleDFS(adj,vis,V,n,it,i))
            return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        int n = edges.size();
        for(auto &edge:edges){ // can also write (auto edge : edges) but it will create copy, so extra memory usage
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
         for(int i=0; i<V; i++){
             if(!vis[i] && isCycleDFS(adj,vis,V,n,i,-1))
             return true;
         }
         return false;
    }
};