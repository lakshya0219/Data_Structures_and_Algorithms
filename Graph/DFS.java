import java.util.*;
class Solution{
public static void dfsTrav(int node, List<Integer> res, boolean[] vis, List<List<Integer>> adj){
    vis[node]=true;
    res.add(node);
    for(int it : adj.get(node)){
        if(!vis[it]){
            dfsTrav(it, res, vis, adj);
        }
    }
}
}
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices");
        int v = sc.nextInt();
        System.out.println("Enter the number of edges");
        int e = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<v; i++){
            adj.add(new ArrayList<>());
        }
        System.out.println("Enter "+ e+" edges in u,v format");
        for(int i=0; i<e; i++){
            int u = sc.nextInt();
            int vertex = sc.nextInt();
            adj.get(u).add(vertex);
            adj.get(vertex).add(u);
        }
        boolean[] vis = new boolean[v];
        List<Integer> res = new ArrayList<>();
        Solution obj = new Solution();
         // Static method call without object
        Solution.dfsTrav(0, res, vis, adj);
        // obj.dfsTrav(0,res,vis,adj);
        for(int i: res){
            System.out.print(i+" ");
        }
        System.out.println();
        sc.close();
    }
}
