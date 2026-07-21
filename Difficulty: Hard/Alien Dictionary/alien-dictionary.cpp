class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>>adj(26);
        vector<int>InDeg(26,0);
        unordered_set<char> unique;
        
        for (auto &w : words) {
            for (char c : w) unique.insert(c);
        }
        
        for(int i=0; i<words.size()-1; i++){
            string str1 = words[i];
            string str2 = words[i+1];
            
            int len = min(str1.size(), str2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (str1[j] != str2[j]) {
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    InDeg[str2[j]-'a']++;
                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && str1.size() > str2.size()) return "";
        }
        
        queue<int>q;
        for(char c: unique){
            if(InDeg[c-'a'] == 0) q.push(c-'a');
        }
        
        string ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node+'a');
            
            for(int i=0; i<adj[node].size(); i++){
                InDeg[adj[node][i]]--;
                if(InDeg[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        
        if(ans.size() == unique.size()) return ans;
        
        return "";
    }
};