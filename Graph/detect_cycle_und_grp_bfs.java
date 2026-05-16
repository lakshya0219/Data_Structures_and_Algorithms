import java.util.*;

class Solution {
    boolean isCycleBfs(List<List<Integer>> adj, boolean[] vis, int node, int parent){
        vis[node]=true;
        Queue<int []> q = new LinkedList<>();
        q.add(new int[]{node,parent});
        while(!q.isEmpty()){
            int[] pair = q.poll();
            int child = pair[0];
            int pr = pair[1];
            for(int i: adj.get(child)){
                if(i==pr)
                continue;
               else if(vis[i])
                return true;
                else{
                    vis[i] = true;
                    q.add(new int[]{i,child});
                }
            }
        }
        return false;
    }
    public boolean isCycle(int V, int[][] edges) {
        boolean[] vis = new boolean[V];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<edges.length; i++){
            int u= edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        for(int i=0; i<V; i++){
            if(!vis[i] && isCycleBfs(adj,vis,i,-1))
            return true;
        }
        return false;
    }
}