 //code
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <=2) return n;
     vector<vector<int>>& p= points;
     
      int maxi =2;
  for(int i=0; i<n; i++){
     for(int j=i+1; j<n; j++){
         int total =2;
         for(int k=0; k<n; k++){
             if(k != i and k != j){
if((p[j][1]-p[i][1])*(p[i][0]-p[k][0]) == (p[i][1]-p[k][1])*(p[j][0]-p[i][0])) total++;
         }
            }
             maxi = max(maxi , total);          
            }
        }
         return maxi;
    }
};
