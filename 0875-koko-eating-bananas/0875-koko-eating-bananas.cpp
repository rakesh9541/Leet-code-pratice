class Solution {
public:

    bool ispossible(int m, vector<int> & piles, int h)
    {
        int c=0;
        for(int i=0;i<piles.size();i++)
        {
            c+=(piles[i]/m);
            if(piles[i]%m>0)
                c++;
        }
        if(c<=h)
         return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
     sort(piles.begin(),piles.end());
     int len = piles.size();
     int ans = piles[len-1];
     int l = 1;
     while(l<ans)
     {
         int m = l+(ans-l)/2;
         if(ispossible(m,piles,h))
            ans=m;
         else
             l=m+1;
     }
     return ans;
    }
};