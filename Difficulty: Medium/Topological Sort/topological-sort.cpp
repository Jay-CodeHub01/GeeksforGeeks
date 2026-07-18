class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int>ans;
        
        // Calculate InDegree: 
        vector<int>InDeg(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        
        // Push all vertex whose indegree is ZERO: 
        for(int i=0; i<V; i++){
            if(InDeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Neighbour of node ki InDegree ko 1 se kam karo: 
            for(int j=0; j<adj[node].size(); j++){
                InDeg[adj[node][j]]--;
                
                if(InDeg[adj[node][j]] == 0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        
        return ans;
    }
};