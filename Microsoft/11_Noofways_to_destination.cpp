//Code
#define ll long long
class Solution {
public:
     int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int , int>> adj[n];
        for(auto it: roads){
            adj[it[0]] .push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }        
   
         vector<ll> dist(n , 1e18) , ways(n,0);
         dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> q;
        q.push({0,0});
        while(!q.empty()){
           
             auto it = q.top();
            ll node = it.first;
            ll dis = it.second;
            q.pop();  
            
            for(auto itr:adj[node]){
               ll adjnode = itr.first;
                ll time = itr.second;
               if(dis+time < dist[adjnode]){
                    dist[adjnode] = dis+time;
                   q.push({adjnode , dis+time});
                   ways[adjnode] = ways[node];
                }
              else if( dis+time == dist[adjnode]){
                         ways[adjnode] = (ways[adjnode] + ways[node])%mod;
             }
        }
        }
        return ways[n-1]%mod;
    }
};
