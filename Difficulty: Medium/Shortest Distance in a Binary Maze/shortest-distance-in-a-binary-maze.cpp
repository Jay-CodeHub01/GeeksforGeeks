class Solution {
  public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int n = mat.size();
        int m = mat[0].size();

        // If source or destination is blocked
        if (mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0) return -1;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<tuple<int,int,int>> q; // (i, j, steps)

        q.push({src[0], src[1], 0});
        visited[src[0]][src[1]] = true;

        while (!q.empty()) {
            auto [i, j, steps] = q.front();
            q.pop();

            // If destination reached
            if (i == dest[0] && j == dest[1]) return steps;

            for (int k = 0; k < 4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j, n, m) && mat[new_i][new_j] == 1 && !visited[new_i][new_j]) {
                    visited[new_i][new_j] = true;
                    q.push({new_i, new_j, steps + 1});
                }
            }
        }

        return -1; // Destination not reachable
    }
};
