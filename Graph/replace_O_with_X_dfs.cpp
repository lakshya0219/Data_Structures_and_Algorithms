class Solution {
    private: 
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis,int i, int j, int n,
    int m, int delrow[], int delcol[]){
        vis[i][j]=true;
        for(int deli=0; deli<4; deli++){
            int nrow=i+delrow[deli];
            int ncol=j+delcol[deli];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow]
            [ncol]=='O'){
                dfs(grid,vis,nrow,ncol,n,m,delrow,delcol);
            }
        }
    }
  public:
    void fill(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int delrow[] ={-1,0,1,0};
        int delcol[] ={0,1,0,-1};
        //traversing first and last row
        for(int j=0; j<m; j++){
            //travering first row
            if(!vis[0][j] && grid[0][j]=='O'){
                dfs(grid,vis,0,j,n,m,delrow,delcol);
            }
            //traversing last row
            if(!vis[n-1][j] && grid[n-1][j]=='O'){
                 dfs(grid,vis,n-1,j,n,m,delrow,delcol);
            }
        }
        //traversing first and last column
        for(int i=0; i<n; i++){
            //traversing first row
            if(!vis[i][0] && grid[i][0]=='O'){
                 dfs(grid,vis,i,0,n,m,delrow,delcol);
            }
             if(!vis[i][m-1] && grid[i][m-1]=='O'){
                 dfs(grid,vis,i,m-1,n,m,delrow,delcol);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j])
                grid[i][j]='X';
            }
        }
    }
};