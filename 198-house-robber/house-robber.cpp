class Solution {
public:
int f(vector<int>nums,int n,vector<int>&dp)
{
    if(n==0)
        return nums[n];
    if(n<0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int pick=nums[n]+f(nums,n-2,dp);
    int notpick=0+f(nums,n-1,dp);
    return dp[n]=max(pick,notpick);
}
 int rob(vector<int>&nums) {
     int n=nums.size();
     vector<int>dp(nums.size()+1,-1);
    return f(nums,n-1,dp);



      /*  int n = nums.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2;i<=nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n]; */
    }
};