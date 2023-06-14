class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0,mini=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            mini=min(mini,prices[i]);
            p=max(p,prices[i]-mini);
        }
        return p;
        
    }
};