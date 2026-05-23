import java.util.*;
class Solution {
    public void distinctDfs(int[][] grid,boolean[][] vis,List<String> vec, int n, int m,
    int row, int col, int row0, int col0){
        vis[row][col]=true;
        vec.add((row-row0)+","+(col-col0));
        int[] delrow={-1,0,1,0};
        int[] delcol={0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                distinctDfs(grid,vis,vec,n,m,nrow,ncol,row0,col0);
            }
        }
    }
    int countDistinctIslands(int[][] grid) {
        // Your Code here
     int n=grid.length;
     int m=grid[0].length;
     boolean[][] vis = new boolean[n][m];
     Set<List<String>> st = new HashSet<>();
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(!vis[i][j] && grid[i][j]==1){
                 List<String> vec = new ArrayList<>();
                 distinctDfs(grid,vis,vec,n,m,i,j,i,j);
                 st.add(vec);
             }
         }
     }
     return st.size();
    }
}