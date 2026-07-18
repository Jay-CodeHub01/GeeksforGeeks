class Solution {
  public:
    bool DetectCycle(int node, vector<vector<int>>& adj, vector<bool>&path,vector<bool>&visited){
        visited[node] = 1;
        path[node] = 1;
        
        for(int i=0; i< adj[node].size(); i++){
            if(path[adj[node][i]]) {
                return 1;
            }
            if(!visited[adj[node][i]] && DetectCycle(adj[node][i], adj, path, visited)){ 
                return 1;
            }
        }
        
        path[node] = 0;
        return 0;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && DetectCycle(i,adj, path, visited)){
                return true;
            }
        }
        
        return false;
    }
};