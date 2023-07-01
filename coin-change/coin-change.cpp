class Solution {
public:
    int coinChange(vector<int>& coins,int amount) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int target=0;target<=amount;target++)
        {
           if((target%coins[0])==0)
            dp[0][target]= target/coins[0];
           else
               dp[0][target]=1e8; 
        }

        for(int index=1;index<n;index++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notTake=dp[index-1][target];
                int take=1e8;
                if(target>=coins[index])
                {
                    take=1+dp[index][target-coins[index]];
                }
                dp[index][target]=min(take,notTake);
            }
        }
        int ans= dp[n-1][amount];
        if(ans>=1e8) 
            return -1;
        return ans;
    }
};