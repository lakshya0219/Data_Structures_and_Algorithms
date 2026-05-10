class Solution {
    public static void dfsTrav(int[][] image,int[][] result,int[] delrow, int[] delcol,
    int sr, int sc, int n, int m,int inicolor, int newcolor){
        result[sr][sc]=newcolor;
        for(int i=0; i<4; i++){
            int nrow=sr+delrow[i], ncol=sc+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && result[nrow][ncol]!=newcolor 
            && image[nrow][ncol] == inicolor)
            {
                dfsTrav(image, result, delrow, delcol,nrow,ncol,n,m,inicolor,newcolor);
            }
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        if(iniColor==newColor)
        return image;
        int n = image.length; int m = image[0].length;
        int[][] result = new int[n][m];
        for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        result[i][j] = image[i][j];
    }
}
   int delRow[]={-1,0,+1,0};
               int delCol[] = {0,+1,0,-1};
        dfsTrav(image, result,delRow, delCol, sr,sc,n,m,iniColor, newColor);
        return result;
    }
}