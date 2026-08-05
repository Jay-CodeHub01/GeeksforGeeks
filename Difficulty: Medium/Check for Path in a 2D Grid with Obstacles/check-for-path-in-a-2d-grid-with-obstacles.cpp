class Solution {
  public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    int m,n;
  
    bool dfs(vector<vector<int>>& mat, int i,int j){
        if(i<0 || j<0 || i>= m || j>=n || mat[i][j] == 0 || mat[i][j] == -1) return false;
        
        if(mat[i][j] == 2){
            return true;
        }
        
        mat[i][j] = -1;
        
        for(int k=0; k<4; k++){
            int ni = i + row[k], nj = j + col[k];
            if(dfs(mat, ni, nj)) return true;
        }
        
        return false;
    }
    
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        m = mat.size();
        n = mat[0].size();
        
        int a,b;
        
        for(int i =0; i<m ; i++){
            for(int j=0; j<n ; j++){
                if(mat[i][j] == 1){
                    a = i;
                    b = j;
                    break;
                }
            }
        }
        
        return dfs(mat, a,b);
        
    }
};