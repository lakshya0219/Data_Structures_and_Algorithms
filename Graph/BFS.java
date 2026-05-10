import java.util.*;

class Solution {
    // DFS wala method (comment kardo ya rakh do)
    // public static void dfsTrav(int node, List<Integer> res, boolean[] vis, List<List<Integer>> adj) {
    //     vis[node] = true;
    //     res.add(node);
    //     for(int it : adj.get(node)) {
    //         if(!vis[it]) {
    //             dfsTrav(it, res, vis, adj);
    //         }
    //     }
    // }
    
    // BFS method - minimal changes
    public static void bfsTrav(int start, List<Integer> res, boolean[] vis, List<List<Integer>> adj) {
        Queue<Integer> q = new LinkedList<>();  // NEW: Queue instead of recursion
        q.add(start);
        vis[start] = true;
        
        while(!q.isEmpty()) {                   // NEW: Loop instead of recursion
            int node = q.poll();
            res.add(node);
            
            for(int it : adj.get(node)) {
                if(!vis[it]) {
                    vis[it] = true;
                    q.add(it);                  // NEW: Queue mein add
                }
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
        for(int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
        
        System.out.println("Enter " + e + " edges in u,v format");
        for(int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int vertex = sc.nextInt();
            adj.get(u).add(vertex);
            adj.get(vertex).add(u);
        }
        
        boolean[] vis = new boolean[v];
        List<Integer> res = new ArrayList<>();
        
        // BFS call - SIRF YAHAN CHANGE KIYA (DFS se BFS)
        Solution.bfsTrav(0, res, vis, adj);  // Pehle dfsTrav tha
        
        System.out.println("BFS Traversal:");
        for(int i : res) {
            System.out.print(i + " ");
        }
        System.out.println();
        
        sc.close();
    }
}