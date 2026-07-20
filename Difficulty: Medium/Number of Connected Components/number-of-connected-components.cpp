class Solution {
  public:
    int m,n;
    
    void dfs(vector<vector<int>>& adj, int node,vector<bool>& visited){
        visited[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                dfs(adj,adj[node][i], visited);   
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>>adj(V);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool>visited(V,0);
        int cnt=0;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                cnt++;
            }
        }
        
        return cnt;
        
    }
};