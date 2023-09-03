class Solution {
public:
   /* int f(int n,int r)
    {
        if(r>n) return 0;
        if(r==0 || r==n) return 1;
        else
            return f(n-1,r-1)+f(n-1,r);
    } */
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=n-1;
        long long res=1;
        for(int i=1;i<=r;i++)
            res=res*(N-r+i)/i;
        return res;
        
    }
};