class Solution {
  public:
  
  void DFS(int node, vector<vector<int>>&adj, vector<int>&visited, stack<int>&s){
      visited[node]= 1;
      
      for(int j=0; j<adj[node].size();j++){
          if(!visited[adj[node][j]])
          DFS(adj[node][j], adj, visited, s);
      }
      
      s.push(node);
  }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int>visited(V,0);
        stack<int>s;
        
        for(int i=0 ; i<V; i++){
            if(!visited[i]){
                DFS(i,adj,visited,s);
            } 
        }
        
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        
        return ans;
    }
};