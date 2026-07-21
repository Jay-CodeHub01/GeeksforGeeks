class Solution {
  public:
    int topological(vector<vector<int>>&adj,int node){
        vector<int>InDeg(adj.size(), 0);
        
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }
        
        queue<int>q;
        for(int i=0; i<adj.size(); i++){
            if(InDeg[i] == 0){
                q.push(i);
            }
        }
        
        int cnt=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(int i=0; i<adj[node].size(); i++){
                InDeg[adj[node][i]]--;
                if(InDeg[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        
        return cnt;
        
    }
    bool isPossible(int n, vector<pair<int, int>>& pre) {
        // code here
        vector<vector<int>>adj(n);
        for(auto &e: pre){
            adj[e.second].push_back(e.first);
        }
        
        return (topological(adj,0) == n);
        
    }
};