class Solution {
  public:
    int minFlips(string& s) {
        // code here
        int costA=0,costB=0;
        int n = s.size();
        for(int i=0;i<n ; i++){
            char A = (i%2 == 0)?'0':'1';
            char B = (i%2 == 0)?'1':'0';
            
            if(s[i] != A) costA++;
            if(s[i] != B) costB++;
        }
        
        return min(costA,costB);
    }
};
