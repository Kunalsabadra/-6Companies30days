//solution


class Solution {
public:
      vector<vector<int>> subsets;
      void genrate(vector<int> &subset , int i , int k , int n){
           if(k == subset.size() and n == 0) { 
               subsets.push_back(subset);
               return;
           }
           if(i >= 10  or( n != 0 and i > n ))
           return;
           genrate(subset , i+1 , k , n);
           subset.push_back(i);
           genrate(subset , i+1 ,  k , n-i);
           subset.pop_back();
      }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        genrate(subset , 1 ,k , n);
        return subsets;    
    }
};
