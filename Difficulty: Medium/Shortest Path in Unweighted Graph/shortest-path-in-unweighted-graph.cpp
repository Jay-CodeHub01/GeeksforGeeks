class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int>dist(V,-1);
        vector<bool>visited(V,0);
        
        queue<int>q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neigh: adj[node]){
                if(visited[neigh]) continue;
                
                visited[neigh] = 1;
                q.push(neigh);
                dist[neigh] = dist[node]+1;
            }
        }
        
        return dist[dest];
    }
};
