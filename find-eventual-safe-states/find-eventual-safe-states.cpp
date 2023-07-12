class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis)
    {
        if(pathvis[i])
            return true;
        if(vis[i])
            return false;
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto x: graph[i]){
            if(dfs(x,graph,vis,pathvis))return true;
        }
        pathvis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> res;
        for(int i=0; i<n; i++){
            if(!dfs(i,graph,vis,pathvis))
                res.push_back(i);
        }
        return res;
    }
};