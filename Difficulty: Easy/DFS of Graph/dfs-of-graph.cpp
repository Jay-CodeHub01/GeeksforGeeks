class Solution {
  public:
  
  void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor, adj, visited, ans);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n, false);

        // Start DFS from node 0 (you can change this if needed)
        DFS(0, adj, visited, ans);

        return ans;
    }
};