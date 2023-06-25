class Solution {
public:
    int solve(int i, int j, int& n, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(i == n-1) 
            return dp[i][j] = arr[i][j];
        if(dp[i][j] != -1) 
            return dp[i][j];
        int l=solve(i+1, j, n, arr, dp);
        int r=solve(i+1, j+1, n, arr, dp);
        return dp[i][j] = min(l, r) + arr[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector(n, -1));
        return solve(0, 0, n , triangle, dp);
    }  
};