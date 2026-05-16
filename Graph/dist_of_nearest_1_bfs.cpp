vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> adj(n, vector<int>(m, -1));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false)); 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                   adj[i][j] = 0;
                   vis[i][j] = true;
                   q.push({{i, j}, 0});
                }
            }
        }
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            adj[row][col] = tm;
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]) { 
                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, tm + 1}); 
                }
            }
        }
        return adj;
    }