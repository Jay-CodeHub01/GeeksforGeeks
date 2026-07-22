class Solution {
  public:
    void DFS(int node, vector<pair<int,int>> adj[], stack<int>& s1, vector<bool>& visited){
        visited[node] = 1;
        
        for(int j=0; j<adj[node].size(); j++){
            if(!visited[adj[node][j].first])
            DFS(adj[node][j].first, adj, s1, visited);
        }
        
        s1.push(node);
    }
    
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v,w});
        }
        
        
        
        vector<bool>visited(V,0);
        stack<int>s1;
        DFS(0,adj, s1, visited);
        
        
        vector<int>dist(V,INT_MAX);
        dist[0] = 0;
        
        while(!s1.empty()){
            int node = s1.top();
            s1.pop();
            
            for(int j = 0; j<adj[node].size() ; j++){
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                
                dist[neighbour] = min(dist[neighbour], weight+dist[node]);
            }
            
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        
        return dist;
        
        
        
    }
};
