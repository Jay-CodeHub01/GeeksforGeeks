class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int>color(V,-1);
        queue<int>q;
        
        
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                q.push(0);
                color[0] = 0;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    int c = color[node];
                    
                    for(int i=0; i<adj[node].size(); i++){
                        if(color[adj[node][i]] == -1){
                            if(color[node]){
                                color[adj[node][i]] = 0;
                            }
                            else{
                                color[adj[node][i]] = 1;
                            }
                            q.push(adj[node][i]);
                        }
                        else{
                            if(color[adj[node][i]] == color[node]){
                                return 0;
                            } 
                        }
                    }
                }
                return 1;
            }
        }
        
    }
};