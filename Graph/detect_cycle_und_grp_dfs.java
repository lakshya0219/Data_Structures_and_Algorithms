import java.util.*;
public class detect_cycle_und_grp_dfs {
    
}
class Solution {
    public boolean isCycleDfs(List<List<Integer>> adj, boolean[] vis, int child, int parent){
        vis[child] = true;
        for(int it : adj.get(child)){
            if(it==parent)
            continue;
            if(vis[it])
            return true;
            if(isCycleDfs(adj, vis, it,child))
            return true;
        }
        return false;
    }
    public boolean isCycle(int V, int[][] edges) {
        List<List<Integer>> adj= new ArrayList<>();
        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        boolean[] vis = new boolean[V];
        for(int i=0; i<V; i++){
            if(!vis[i] && isCycleDfs(adj,vis,i,-1))
            return true;
        }
        return false;
    }
}