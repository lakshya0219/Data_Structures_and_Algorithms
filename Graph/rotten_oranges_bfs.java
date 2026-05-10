import java.util.*;

class Solution {
    public int orangesRot(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] vis = new int[n][m];
        
        // Queue to store {row, col, time}
        Queue<int[]> q = new LinkedList<>();
        
        // Initialization
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    vis[i][j] = 2;
                    q.add(new int[]{i, j, 0});  // {row, col, time}
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        // Direction arrays
        int[] delrow = {-1, 0, 1, 0};
        int[] delcol = {0, 1, 0, -1};
        
        int tmax = 0;
        
        // BFS
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int r = current[0];
            int c = current[1];
            int tm = current[2];
            
            tmax = Math.max(tmax, tm);
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
                    mat[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    vis[nrow][ncol] = 2;
                    q.add(new int[]{nrow, ncol, tm + 1});
                }
            }
        }
        
        // Check for any fresh orange left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && mat[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return tmax;
    }
}