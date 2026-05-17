import java.util.*;
class Solution {
    void dfs(char[][] grid, boolean[][] vis, int i, int j, int n, int m, int[] delrow, int[] delcol){
        vis[i][j]=true;
        for(int x=0; x<4; x++){
            int nrow=i+delrow[x];
            int ncol=j+delcol[x];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='O' && !vis[nrow][ncol]){
                vis[nrow][ncol]=true;
                dfs(grid,vis,nrow,ncol,n,m,delrow,delcol);
            }
        }
    }
    public void fill(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean [][] vis = new boolean[n][m];
        int[] delrow = {-1,0,1,0};
        int[] delcol = {0,1,0,-1};
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]=='O'){
                dfs(grid,vis,0,j,n,m,delrow,delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j]=='O'){
                dfs(grid,vis,n-1,j,n,m,delrow,delcol);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]=='O'){
                dfs(grid,vis,i,0,n,m,delrow,delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1]=='O'){
                dfs(grid,vis,i,m-1,n,m,delrow,delcol);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==false && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
}
 