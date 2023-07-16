class Solution {
    private:
    void dfs(int n,int m,int iniColor,int delRow[],int delCol[],vector<vector<int>>& image,vector<vector<int>>& ans,int row,int col,int color){
        ans[row][col]=color;
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==iniColor){
                dfs(n,m,iniColor,delRow,delCol,image,ans,nrow,ncol,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
        int n=image.size();
        int m=image[0].size();
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        dfs(n,m,iniColor,delRow,delCol,image,ans,sr,sc,color);
        return ans;
    }
};