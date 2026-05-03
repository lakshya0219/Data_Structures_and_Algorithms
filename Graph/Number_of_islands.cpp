
class Solution {
    private:
    //dfs technique:
    //   void dfsTrav(vector<vector<char>>& grid, vector<vector<int>>& visited, 
    //              int row, int col, int n, int m) {
    //     // Mark current cell as visited
    //     visited[row][col] = 1;
        
    //     // Check all 8 directions
    //     for(int delrow = -1; delrow <= 1; delrow++) {
    //         for(int delcol = -1; delcol <= 1; delcol++) {
    //             int nrow = row + delrow;
    //             int ncol = col + delcol;
                
    //             // Check boundary and if it's land and not visited
    //             if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
    //                visited[nrow][ncol] != 1 && grid[nrow][ncol] == 'L') {
    //                 dfsTrav(grid, visited, nrow, ncol, n, m);
    //             }
    //         }
    //     }
    // }
    // bfs technique
    void bfsTrav(vector<vector<char>>& grid, vector<vector<int>> &visited, int row, int col, int n, int m){
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int toprow=q.front().first, topcol=q.front().second;
            q.pop();
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow = toprow+delrow, ncol = topcol+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=1 && grid[nrow][ncol]=='L'){
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=1;
                    }
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]!=1 && grid[i][j]=='L'){
                    count++;
                    bfsTrav(grid, visited, i, j,n,m);
                }
            }
        }
        return count;
    }
};