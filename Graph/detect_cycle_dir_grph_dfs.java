import java.util.*;
class Solution {
    public boolean isCycleDfs(List<List<Integer>> adj, boolean[] vis, boolean[] inRecur, int node){
        vis[node]=true;
        inRecur[node]=true;
        for(int i: adj.get(node)){
            if(!vis[i] && isCycleDfs(adj,vis,inRecur,i))
            return true;
            else if(inRecur[i])
            return true;
        }
        inRecur[node]=false;
        return false;
    }
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        boolean[] vis = new boolean[V];
        boolean[] inRecur = new boolean[V];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
        }
        for(int i=0; i<V; i++){
            if(!vis[i] && isCycleDfs(adj,vis,inRecur,i))
            return true;
        }
        return false;
    }
}