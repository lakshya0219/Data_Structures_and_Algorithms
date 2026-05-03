class Solution {
    private:
    void dfsTrav(int n, int m, vector<vector<int>>& image,vector<vector<int>>& ans,
    int sr, int sc,int iniColor, int newColor, int delRow[], int delCol[]){
        ans[sr][sc] = newColor;
        for(int i=0; i<4; i++){
            int nrow = sr+delRow[i];
            int ncol = sc+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor
            && ans[nrow][ncol]!=newColor){
                dfsTrav(n,m,image,ans,nrow, ncol, iniColor, newColor, delRow, delCol);
            }
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
               int n = image.size(), m = image[0].size();
               vector<vector<int>> ans = image;
               int iniColor = image[sr][sc];
                    if(iniColor == newColor) {
            return image;
        }
               int delRow[]={-1,0,+1,0};
               int delCol[] = {0,+1,0,-1};
               dfsTrav(n,m,image,ans,sr,sc,iniColor,newColor,delRow,delCol);
               return ans;
        
    }
};