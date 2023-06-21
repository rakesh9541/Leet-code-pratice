class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long sum=0;
        for(auto i:candies)
            sum+=i;
        int mn=*min_element(candies.begin(),candies.end());
        long long s=mn/((k+n-1)/n);
        long long e=sum/k;
        long long m;
        while(s<=e)
        {
            m=(s+e)/2;
            long long ct=0;
            if(m==0)
                ct=LONG_MAX;
         else
         {
            for(auto i:candies)
                ct+=(i/m);
         }
            if(ct<k)
                e=m-1;
            else
                s=m+1;
        }
        return e;
    }
};