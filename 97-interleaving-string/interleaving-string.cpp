class Solution {
public:
    string s1,s2,s3;
    int dp[101][101];
    bool rec(int i,int j,int k){
        if(k == s3.size() && i == s1.size() && j == s2.size()){
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i < s1.size() && j < s2.size() && s1[i] == s2[j] && s1[i] == s3[k]){
            return dp[i][j] = ((rec(i+1, j, k+1) || rec(i, j+1, k+1)));
        }
        else if(i < s1.size() && s1[i] == s3[k])
            return dp[i][j] = rec(i+1,j,k+1);
        else if(j < s2.size() && s2[j] == s3[k])
            return dp[i][j] = rec(i, j+1, k+1);
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memset(dp, -1, sizeof(dp));
        return rec(0,0,0);
    }
};