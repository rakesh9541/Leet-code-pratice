class Solution {
public:
    int f(vector<int> &nums, int target, int index, int size,vector<int>&dp)
    {
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target]!=-1) return dp[target];
        
        int ways = 0;   
        for(int i = 0; i<size; i++)
        {
            ways +=f(nums, target - nums[i], i, size,dp);
        }
        return dp[target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return f(nums, target, 0, nums.size(),dp);
    }
};