class Solution {
    public static void dfsTrav(char[][] grid, boolean[][] vis, int n, int m, int i, int j){
        vis[i][j]=true;
       for(int ii=-1; ii<=1; ii++){
           for(int jj=-1; jj<=1; jj++){
               int nrow = i+ii; int ncol= j+jj;
               if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='L'){
                   dfsTrav(grid, vis, n, m, nrow, ncol);
               }
           }
       }
    }
    public int countIslands(char[][] grid) {
        // Code here
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                    dfsTrav(grid,vis,n,m,i,j);
                    count++;
                }
            }
        }
        return count;
    }
}