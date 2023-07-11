class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0)
                    dp[i]=max(dp[i],dp[prev]+1);
            }
            maxi=max(dp[i],maxi);
        }
        vector<int>lis;
        int prev = -1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==maxi && (prev == -1 || prev % nums[i] == 0))
            {
                lis.push_back(nums[i]);
                maxi--;
                prev = nums[i];
            }
        }
        return lis;
    }
};