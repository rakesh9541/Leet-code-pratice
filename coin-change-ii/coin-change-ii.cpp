class Solution {
public:
int fun(vector<int>& arr,int ind, int T, vector<vector<long>>& dp)
{
    if(ind == 0)
        return (T%arr[0]==0);
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    int notTaken = 0+fun(arr,ind-1,T,dp);
    
    int taken = 0;
    if(arr[ind] <= T)
        taken = fun (arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken + taken;
}

 int change(int amount, vector<int>& coins)
 {  
     int n = coins.size();
     vector<vector<long>> dp(n,vector<long>(amount+1,-1));
     
    return fun(coins,n-1, amount, dp);
 }
 
};