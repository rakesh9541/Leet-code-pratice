class Solution {
public:
    int  fun(int index,vector<int>& prices,int fee,int buy,vector<vector<int>>&dp){
     int n=prices.size();
     int profit=0;
     if(index>=n)return 0;
     if(dp[index][buy]!=-1)return dp[index][buy];
     if(buy){
         int take=-prices[index]+fun(index+1,prices,fee,0,dp);
         int nottake=0+fun(index+1,prices,fee,1,dp);
         profit=max(take,nottake);
     }
     else{
         int sell=prices[index]-fee+fun(index+1,prices,fee,1,dp);
         int notsell=0+fun(index+1,prices,fee,0,dp);
         profit=max(sell,notsell);
     }
     return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return fun(0,prices,fee,1,dp);
    }
};