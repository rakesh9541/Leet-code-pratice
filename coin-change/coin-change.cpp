class Solution {
public:
    int coinChange(vector<int>& coins,int amount) 
    {
        int n=coins.size();
        vector<int>prev(amount+1,-1);
        vector<int>curr(amount+1,-1);
        for(int target=0;target<=amount;target++)
        {
           if((target%coins[0])==0)
            prev[target]= target/coins[0];
           else
               prev[target]=1e8; 
        }

        for(int index=1;index<n;index++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notTake=prev[target];
                int take=1e8;
                if(target>=coins[index])
                {
                    take=1+curr[target-coins[index]];
                }
                curr[target]=min(take,notTake);
            }
            prev=curr;
        }
        int ans= prev[amount];
        if(ans>=1e8) 
            return -1;
        return ans;
    }
};