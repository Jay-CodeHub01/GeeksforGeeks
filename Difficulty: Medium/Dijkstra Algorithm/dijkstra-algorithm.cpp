class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
         // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e: edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); // undirected
        }

        // Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min-heap: (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            // Skip if we already found a better path
            if(d > dist[node]) continue;

            for(auto &p : adj[node]){
                int neigh = p.first, weight = p.second;
                if(dist[node] + weight < dist[neigh]){
                    dist[neigh] = dist[node] + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
};