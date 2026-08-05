class Solution {
  public:
  
    int n;
    vector<string> res;
    vector<vector<int>> visited;
  
    void dfs(vector<vector<int>>& maze, int i, int j, string path){
        if(i == n-1 && j==n-1){
            res.push_back(path);
            return;
        }
        
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        char dir[] = {'D','L','R','U'};
        
        for(int k=0; k<4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if(ni>=0 && nj>=0 && ni<n && nj<n && maze[ni][nj] == 1 && !visited[ni][nj]) {
                visited[ni][nj] = 1;
                dfs(maze, ni, nj, path + dir[k]);
                visited[ni][nj] = 0;
            }
        }
    
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze.size();
        res.clear();
        visited.assign(n, vector<int>(n, 0));
        
        if(maze[0][0] == 0) return {};
        
        visited[0][0] = 1;
        dfs(maze, 0, 0, "");
        
        sort(res.begin(), res.end());
        return res;
    }
};