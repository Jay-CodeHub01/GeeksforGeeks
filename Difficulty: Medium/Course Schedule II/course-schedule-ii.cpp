class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>>adj(n);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        
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
            
            vector<int>ans;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for(int i=0; i<adj[node].size(); i++){
                    InDeg[adj[node][i]]--;
                    if(InDeg[adj[node][i]] == 0){
                        q.push(adj[node][i]);
                    }
                }
            }
            
            if (ans.size() == n) return ans;
            
            return {};
        
    }
};