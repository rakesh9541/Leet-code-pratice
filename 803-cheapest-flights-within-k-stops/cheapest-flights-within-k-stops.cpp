class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &x : flights){
            int u = x[0];
            int v = x[1];
            int cost = x[2];
            adj[u].push_back({v,cost});
        }

        vector<int> dist(n,INT_MAX); 
        queue<pair<int,int>> qu;
        qu.push({src,0});
        dist[src]=0;

        int step=0;
        while(!qu.empty()&&step<=k){
           
             int N = qu.size();

             while(N--){
                  
               int u = qu.front().first;
               int vcost = qu.front().second;

               qu.pop();
               
               for(pair<int,int> &y : adj[u]){
                   int destination = y.first;
                   int cost = y.second;

                   if(dist[destination]>=cost+vcost){
                       dist[destination]=cost+vcost;

                      qu.push({destination,cost+vcost});

                   }
               }
               
             }
             step++; 
           
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};