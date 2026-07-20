class Solution {
  public:
  
    int m,n;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    void dfs(vector<vector<char>>& grid, int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != 'O') return;
        
        grid[i][j]='S';
        for(int k=0; k<4; k++){
            dfs(grid, i+row[k], j+col[k]);  // FIXED
        }
    }
    
    void fill(vector<vector<char>>& grid) {
        // Code here
        m = grid.size();
        n = grid[0].size();
        
        // Conver all boundary connected O to S
        for(int i=0; i<m; i++){
            dfs(grid, i,0);
            dfs(grid, i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        
        
        // Convert O->X and then S->O;
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j] == 'O'){
                    grid[i][j]='X';
                }
                if(grid[i][j]=='S'){
                    grid[i][j] = 'O';
                }
            }
        }
    }
};