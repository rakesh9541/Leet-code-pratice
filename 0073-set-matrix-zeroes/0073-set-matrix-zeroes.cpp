class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<int>d1(row,-1);
        vector<int>d2(col,-1);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    d1[i]=0;
                    d2[j]=0;
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(d1[i]==0 || d2[j]==0)
                    matrix[i][j]=0;
            }
        }
    }
};