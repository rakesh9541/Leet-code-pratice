class Solution {
public:
vector<vector<int>> dp; 
int fun(vector<int>& nums,int i,int j) {
    if(i > j)
        return 0;
    if(dp[i][j] != -1) 
        return dp[i][j];
    int take_left = nums[i] + min(fun(nums,i+2,j), fun(nums,i+1,j-1));
    int take_right = nums[j] + min(fun(nums,i+1,j-1), fun(nums,i,j-2));
    dp[i][j] = max(take_left, take_right);
    return dp[i][j];
}

    bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    int player1 = fun(nums, 0, n-1);
    return 2 * player1 >= total;
}

};