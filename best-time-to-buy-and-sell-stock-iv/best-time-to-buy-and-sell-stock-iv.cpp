class Solution {
public:
    int fun(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (cap == 0) return 0;
        if (ind == n) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if (buy) return dp[ind][buy][cap] = max(-prices[ind] + fun(ind+1, 0, cap, prices, n, dp), 0 + fun(ind+1, 1, cap, prices, n, dp));
        else return dp[ind][buy][cap] = max(prices[ind] + fun(ind+1, 1, cap-1, prices, n, dp), 0 + fun(ind+1, 0, cap, prices, n, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return fun(0, 1, k, prices, n, dp);
        
    }
};