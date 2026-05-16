class Solution {
  private:
  bool isCycleDFS(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &inRecursion, int node){
      vis[node]=true;
      inRecursion[node]=true;
      for(auto &it: adj[node]){
          if(!vis[it] && isCycleDFS(adj,vis,inRecursion,it))
          return true;
          else if(inRecursion[it]) //matlab vis[it] aur inRecursion[it] dono true h
          return true;
      }
      inRecursion[node]=false;
      return false;
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
      vector<vector<int>> adj(V);
      for(int i=0; i<edges.size(); i++){
          int u=edges[i][0];
          int v= edges[i][1];
          adj[u].push_back(v);
      }
      vector<bool> vis(V,false);
      vector<bool> inRecursion(V,false);
      for(int i=0; i<V; i++){
          if(!vis[i] && isCycleDFS(adj,vis,inRecursion,i))
          return true;
      }
      return false;
    }
};