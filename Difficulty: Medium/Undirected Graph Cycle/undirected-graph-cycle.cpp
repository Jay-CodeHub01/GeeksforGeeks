class Solution {
  public:
  
  bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // skip edge back to parent
            if (visited[neighbor]) return true; // found a back edge → cycle
            if (dfs(neighbor, node, adj, visited)) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Run DFS for each component
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};