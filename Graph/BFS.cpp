#include <bits/stdc++.h>

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
        int visited[v] = {0};
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        vector<int> bfsRes;
        while(!q.empty())
        {
            int node = q.front();
            bfsRes.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                if(visited[it]!=1){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return bfsRes;
    }
};
//SC = O(3N) "a queue of size N, a visited array of size N and a bfsRes vector of size N"
//TC = O(N) + O(2E) "where N is the number of vertices and E is the number of edges in the graph"