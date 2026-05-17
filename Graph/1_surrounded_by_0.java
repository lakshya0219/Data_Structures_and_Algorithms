import java.util.*;
class Solution {
    void dfs(int[][] grid, boolean[][] vis,int i, int j, int n, int m, int[] delrow,
    int[] delcol){
        vis[i][j]=true;
        for(int x=0; x<4; x++){
            int nrow=i+delrow[x];
            int ncol=j+delcol[x];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid,vis,nrow,ncol,n,m,delrow,delcol);
            }
        }
    }
    int cntOnes(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int[] delrow={-1,0,1,0};
        int[] delcol={0,1,0,-1};
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(grid,vis,0,j,n,m,delrow,delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(grid,vis,n-1,j,n,m,delrow,delcol);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(grid,vis,i,0,n,m,delrow,delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(grid,vis,i,m-1,n,m,delrow,delcol);
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};