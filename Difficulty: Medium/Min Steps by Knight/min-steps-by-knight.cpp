class Solution {
  public:
    int row[8] = {2,2,-2,-2,1,-1,1,-1};
    int col[8] = {1,-1,1,-1,2,2,-2,-2};
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        
        knightPos[0]--;
        knightPos[1]--;
        targetPos[0]--;
        targetPos[1]--;
        
        if(knightPos[0] == targetPos[0] && targetPos[1] ==  knightPos[1])
        return 0;
        
        queue<pair<int,int>>q;
        vector<vector<bool>> chess(n, vector<bool>(n,0));
        
        q.push({knightPos[0], knightPos[1]});
        chess[knightPos[0]][knightPos[1]] = 1;
        
        int step = 0;
        
        while(!q.empty()){
            int count = q.size();
            
            while(count--){
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                for(int k=0; k<8 ; k++){
                    int new_i = i+row[k];
                    int new_j = j+col[k];
                    
                    if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && !chess[new_i][new_j]){
                        
                        if(new_i == targetPos[0] && new_j == targetPos[1])
                        return step+1;
                        
                        chess[new_i][new_j] = 1;
                        q.push({new_i , new_j});
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};