class Solution {
    private:
    void dfsTrav(int node, vector<vector<int>> &adjls, vector<bool> &visited){
        visited[node]=true;
        for(auto it: adjls[node]){
            if(!visited[it])
            dfsTrav(it, adjls, visited);
        }
    }
  public:
  //edge list is given in the question
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjls(V);
        //converting edge list into adjacency list
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }
        int count = 0;
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                count++;
                dfsTrav(i,adjls,visited);
            }
        }
        return count;
    }
};