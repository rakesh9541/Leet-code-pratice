class DisjointSet {
    public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUParent(parent[u]);
    }
    void unionByRank(int u,int v){
        int up_u=findUParent(u);
        int up_v=findUParent(v);
        if(up_u==up_v){
            return;
        }
        if(rank[up_v]>rank[up_u]){
            parent[up_u]=up_v;
        }
        else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }
        else{
            parent[up_u]=up_v;
            rank[up_v]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                extra++;
            }
            else {
                ds.unionByRank(u,v);
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)components++;
        }
        if(extra>=components-1)return components-1;
        return -1;
    }
};