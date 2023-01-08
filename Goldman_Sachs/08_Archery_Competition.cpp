class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        int finalMask = 0 , total_score = 0;
          

         for(int i=1; i< (1<<12); i++){ //subset traversal
                int arrows = numArrows;
                bool wrongMask = false;
              int score =0;
                       for(int j=1; j<12;j++){
             if((1 << j) &i){
                 int required_arrows = aliceArrows[j] +1 ;
                 if(arrows-required_arrows >= 0){
                     arrows -= required_arrows;
                     score += j;
                 }
                 else{
                     wrongMask = true;
                     break;
                 }
             }
         }
         if(!wrongMask and score> total_score){
             total_score = score;
             finalMask = i;
         }
         }
         vector<int> ans(12);
         int sum =  numArrows;
         for(int i=1; i<12; i++){
             if((1<<i)& finalMask){
                 ans[i] = aliceArrows[i]+1;
                 sum -= ans[i];
             } 
         }
         if(sum > 0) ans[0] = sum;
    return ans;
    }
};
