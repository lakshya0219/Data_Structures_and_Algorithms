//non-cyclic graph is always bipartite graph
//graph with even number of elements in cycle is bipartite graph
//graph with odd number of elements in cycle in not a bipartite graph

class Solution {
    private:
    bool bipartiteBfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &color,
    int node, int V){
        vis[node] = true;
        color[node]=0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto &it: adj[x]){
                if(!vis[it]){
                    vis[it]=true;
                    color[it] = !color[x];
                    q.push(it);
                } else{
                    if(color[it]==color[x])
                    return false;
                }
            }
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
         vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        vector<int> color(V,-1);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(!bipartiteBfs(adj,vis,color,i,V))
                return false;
            }
        }
        return true;
    }
};