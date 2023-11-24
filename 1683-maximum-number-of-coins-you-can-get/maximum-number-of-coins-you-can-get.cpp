class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum=0;
        int n=piles.size();
        sort(piles.begin(),piles.end());
        for(int i=n/3;i<piles.size();i=i+2)
        {
            sum=sum+piles[i];
        }
        return sum;
    }
};