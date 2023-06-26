class Solution {
public:
    int f(vector<int>& cost, int n,vector<int>&dp) {
        if (n < 2) 
            return cost[n];
        if(dp[n]!=-1) 
            return dp[n];
        int l=cost[n]+f(cost,n-1,dp);
        int r=cost[n]+f(cost,n-2,dp);
        return dp[n]=min(l,r);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(f(cost, n - 1,dp), f(cost, n - 2,dp));
    }
};