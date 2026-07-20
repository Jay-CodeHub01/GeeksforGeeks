class Solution {
  public:
  
    int m,n;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        for(int k =0; k<4 ; k++){
            dfs(grid, i+row[k] , j+col[k]);
        }
    }
    
    
    int countGroups(vector<vector<int>>& grid) {
        // code here
        m = grid.size();
        n = grid[0].size();
        
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};