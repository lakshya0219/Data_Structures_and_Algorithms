import java.util.*;

class Main{
    public static void dfsTrav(int num, boolean[] vis, List<List<Integer>> adj){
        vis[num] = true;
        for(int i: adj.get(num)){
            if(!vis[i])
            dfsTrav(i,vis,adj);
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
               dfsTrav(i,vis,adj);
            }
        }
        System.out.println("Count is: "+ count);
        sc.close();
    }
}