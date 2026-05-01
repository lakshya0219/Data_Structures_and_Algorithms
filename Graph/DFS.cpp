   private:
    void dfsTraverse(int node, vector<vector<int>>& adj, vector<int>& dfsres, int vis[]){
        vis[node]=1;
        dfsres.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it])
            dfsTraverse(it,adj,dfsres,vis);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        int vis[v]={0};
        vector<int> dfsres;
        dfsTraverse(0,adj,dfsres,vis);
        return dfsres;
    }