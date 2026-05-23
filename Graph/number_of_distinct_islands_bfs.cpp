// User function Template for C++

class Solution {
    void distinctBfs(vector<vector<int>>& grid,vector<vector<bool>>& vis, set<vector<pair<int,int>>> &st,
    vector<pair<int,int>> &vec, int n, int m, int row, int col, int row0, int col0){
        vis[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            vec.push_back({r-row0,c-col0});
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=r+delrow[i], ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
       int n=grid.size(), m=grid[0].size();
       vector<vector<bool>> vis(n, vector<bool>(m,false));
       set<vector<pair<int,int>>> st;
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(!vis[i][j] && grid[i][j]==1){
                   vector<pair<int,int>> vec;
                   distinctBfs(grid,vis,st,vec,n,m,i,j,i,j);
                   st.insert(vec);
               }
           }
       }
       return st.size();
    }
};
