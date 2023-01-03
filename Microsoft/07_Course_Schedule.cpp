//code
class Solution {
public:
     bool isCycle(int node , vector<int> adj[] , vector<int> &vis){
         if(vis[node] == 1) return true;
          if(vis[node] == 0){
             vis[node] = 1;
                 for(auto it: adj[node]){
                     if(isCycle(it , adj , vis) == true) return true;
                 }
         }
         vis[node] = 2;
         return false;
     }
    
    bool canFinish(int V, vector<vector<int>>& pre) {
        vector<int> adj[V];
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){ 
            if(isCycle(i , adj , vis) == true) return false;
            }
        }
        return true;
    }
};
