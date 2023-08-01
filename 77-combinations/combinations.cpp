class Solution {
public:
    void f(vector<vector<int>>&v,int k,int n,vector<int>&ds,vector<int>&vec,int ind)
    {
        if(ind==n)
        {
            if(ds.size()==k)
            v.push_back(ds);
            return;
        }
        ds.push_back(vec[ind]);
        f(v,k,n,ds,vec,ind+1);
        ds.pop_back();
        f(v,k,n,ds,vec,ind+1);

    }
    vector<vector<int>> combine(int n, int k) {
       
        vector<vector<int>>v;
        vector<int>ds,vec;
         for(int i=1;i<=n;i++)
        {
            vec.push_back(i);
        }
        f(v,k,n,ds,vec,0);
        return v;
    }
};