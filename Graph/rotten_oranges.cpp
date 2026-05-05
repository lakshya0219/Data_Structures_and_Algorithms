int orangesRot(vector<vector<int>>& mat) {
        // code here
         int n = mat.size(), m = mat[0].size();
        int vis[n][m];
         queue<pair<pair<int,int>, int>> q;
         for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                 if(mat[i][j]==2){
                     vis[i][j]=2;
                     q.push({{i,j},0});
                 } else{
                     vis[i][j]=0;
                 }
             }
         }
         int rowArr[]={-1,0,1,0};
         int colArr[]={0,1,0,-1};
         int tmax=0;
         while(!q.empty()){
             int drow=q.front().first.first, dcol=q.front().first.second, tm=q.front().second;
             q.pop();
             tmax=max(tmax,tm);
             for(int i=0; i<4; i++){
                 int nrow = drow+rowArr[i];
                 int ncol = dcol+colArr[i];
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                 {
                     q.push({{nrow,ncol},tm+1});
                     vis[nrow][ncol]=2;
                 }
             }
         }
         for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                 if(vis[i][j]!=2 && mat[i][j]==1)
                 return -1;
             }
         }
         return tmax;
    }