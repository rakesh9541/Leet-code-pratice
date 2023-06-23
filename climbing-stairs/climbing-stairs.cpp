class Solution {
public:
    int f(int n)
    {
        if(n<=1)
            return 1;
        return f(n-1)+f(n-2);
    }
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       int prev2=1;
       int prev1=1;
       for(int i=2;i<=n;i++)
       {
           int curr=prev1+prev2;
           prev2=prev1;
           prev1=curr;
       }
       return prev1;
    
        
    }
};