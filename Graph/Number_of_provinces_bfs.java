import java.util.*;

class Main{
    public static void bfsTrav(int num, boolean[] vis, List<List<Integer>> adj){
        vis[num] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(num);
        while(!q.isEmpty()){
            int node = q.poll();
            for(int i : adj.get(node)){
                if(!vis[i]){
                    vis[i]=true;
                    q.add(i);
                }
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices");
        int v = sc.nextInt();
        System.out.println("Enter number of edges");
        int e = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<v; i++){
            adj.add(new ArrayList<>());
        }
        System.out.println("Enter "+e+" edges in u,v format");
        for(int i=0; i<e; i++){
            int u = sc.nextInt();
            int vertex = sc.nextInt();
            adj.get(u).add(vertex);
            adj.get(vertex).add(u);
        }
        boolean[] vis = new boolean[v];
        int count = 0;
        for(int i=0; i<v; i++){
            if(!vis[i]){
                count++;
               bfsTrav(i,vis,adj);
            }
        }
        System.out.println("Count is: "+ count);
        sc.close();
    }
}

// Enter number of vertices
// 7
// Enter number of edges
// 3
// Enter 3 edges in u,v format
// 0 1
// 2 3
// 4 5
// Count is: 4