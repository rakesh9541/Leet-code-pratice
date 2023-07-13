class Solution {
private:
    int solve(int ind, int n, int k, vector<int>& arr, vector<int>& dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int maxSum = INT_MIN, maxi = INT_MIN, len=0;
        for(int i=ind;i<min(n, ind+k);i++){
            maxi = max(maxi, arr[i]);
            len++;
            int sum = len*maxi + solve(i+1, n, k, arr, dp);
            maxSum = max(sum, maxSum);
        }
        return dp[ind] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, n, k, arr, dp);
    }
};