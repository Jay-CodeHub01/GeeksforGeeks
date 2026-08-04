class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src] = 0;
        int e = edges.size();
        
        for(int i=0; i<V-1; i++){
            
            bool flag = 0;
            
            for(auto &e: edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                
                if(dist[u] == 1e8)
                continue;
                
                if(dist[u] + w < dist[v]){
                    flag = 1;
                    dist[v] = dist[u] + w;
                }
            }
            if(!flag)
            return dist;
        }
        
        // To detuct cycle
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if(dist[u] == 1e8)
            continue;
                
            if(dist[u] + w < dist[v]){
                vector<int>ans;
                ans.push_back(-1);
                return ans;
            }
        }
        
        return dist;
    }
};
