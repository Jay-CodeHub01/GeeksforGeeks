class Solution {
  public:
  
    int m,n;
    int row[8] = {1,-1,0,0,1,-1,1,-1};
    int col[8] = {0,0,1,-1,1,1,-1,-1};
  
    void dfs(vector<vector<char>>&grid, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='W') return;
        
        grid[i][j] = 'W';
        for(int k=0; k<8; k++){
            dfs(grid, i+row[k], j+col[k]);
        }
        // dfs(grid,i+1,j);
        // dfs(grid,i-1,j);
        // dfs(grid,i,j+1);
        // dfs(grid,i,j-1);
        // dfs(grid,i+1,j+1);
        // dfs(grid,i-1,j+1);
        // dfs(grid,i+1,j-1);
        // dfs(grid,i-1,j-1);
        
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        m = grid.size();
        n = grid[0].size();
        
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j] == 'L'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};