import java.util.*;
class Solution {
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        ArrayList<ArrayList<Integer>> res = new ArrayList<>(n);
        for(int i=0; i<n; i++){
            res.add(new ArrayList<>(m));
            for(int j=0; j<m; j++){
                res.get(i).add(0);
            }
        }
        boolean[][] vis = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    vis[i][j]=true;
                     res.get(i).set(j, 1);
                    q.add(new int[]{i,j,0});
                }
            }
        }
        int[] delrow = {-1,0,1,0};
        int[] delcol = {0,1,0,-1};
        while(!q.isEmpty()){
            int[] top = q.poll();
            int r=top[0]; 
            int c=top[1];
            int t=top[2];
             res.get(r).set(c, t);
            for(int i=0; i<4; i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&!vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.add(new int[]{nrow,ncol,t+1});
                }
            }
        }
        return res;
    }
}