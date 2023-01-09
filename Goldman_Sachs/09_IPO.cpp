bool comp(pair<int , int>p1 , pair<int , int> p2){
       return p1.second < p2.second;
  }

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int n = profits.size();
         vector<pair<int , int>> v(n);

         for(int i=0; i<n; i++){
             v[i] = {profits[i] , capital[i]};
         }
         int j =0;
         sort(v.begin() , v.end() , comp);
          priority_queue<int> maxProfit;
          while(k--){
              while(j<n and w >= v[j].second){
                  maxProfit.push(v[j].first);
                  j++;
              }
              if(!maxProfit.empty()){ 
                   w += maxProfit.top();
                  maxProfit.pop();
          }
          }
          return w;
    }
};
