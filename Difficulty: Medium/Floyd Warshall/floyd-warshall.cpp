class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
       int n = dist.size();
        
        // Step 1: Normalize sentinel values
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) {
                    dist[i][j] = 0; // distance to self = 0
                } else if(dist[i][j] == 1e8) {
                    dist[i][j] = INT_MAX; // treat 108 as infinity
                }
            }
        }
        
        // Step 2: Floyd–Warshall relaxation
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    
                    long long newDist = (long long)dist[i][k] + dist[k][j];
                    if(newDist < dist[i][j]) {
                        dist[i][j] = (int)newDist;
                    }
                }
            }
        }
        
        // Step 3: Convert back INF → 108
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] == INT_MAX) {
                    dist[i][j] = 1e8;
                }
            }
        }
    }
};