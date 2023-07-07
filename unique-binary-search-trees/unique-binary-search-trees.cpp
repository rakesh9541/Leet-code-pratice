class Solution {
public:
    int fun(vector<int>&dp,int n,int result)
    {
        if(n==1 || n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=0;i<n;i++)
            result+=fun(dp,i,result)*fun(dp,n-i-1,result);
        return dp[n]= result;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        int result=0;
        return fun(dp,n,result);
        
    }
};