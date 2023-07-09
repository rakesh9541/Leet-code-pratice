class Solution {
public:
        int fun(int ind, vector<int>& prices, int buy, vector<vector<int>> &dp){
        if(ind>=prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        if(buy){
            int a = fun(ind+1, prices, buy, dp);
            int b = -prices[ind] + fun(ind+1, prices, buy-1, dp);  
            return dp[ind][buy]=max(a,b);
        }
        else{
            int a = fun(ind+1, prices, buy, dp);
            int b = prices[ind] + fun(ind+2, prices, buy+1, dp);
            return dp[ind][buy]=max(a, b);
        }
    }
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, -1));
         return  fun(0, prices, true, dp);
    }
};