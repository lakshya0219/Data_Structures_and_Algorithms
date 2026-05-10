class Solution {
    private:
    bool isCycleBFS(vector<vector<int>> &adj, vector<bool> &vis, int V, int n,int i, int parent){
        vis[i]=true;
        queue<pair<int,int>> q;
        q.push({i,parent});
        while(!q.empty()){
            int child = q.front().first, prnt=q.front().second;
            q.pop();
            for(auto &it: adj[child]){
                if(it==prnt)
                continue;
                else if(vis[it])
                return true;
                else
                {
                    q.push({it,child});
                    vis[it]=true;
                }
            }
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
             if(!vis[i] && isCycleBFS(adj,vis,V,n,i,-1))
             return true;
         }
         return false;
    }
};