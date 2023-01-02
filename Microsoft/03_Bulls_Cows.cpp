//solution
/*

Intuition
We will keep the count of frequency of each character if both characters in secret and guess are different we will increment the count at secret position and decrement at guess position . If both characters same we will simply increase the count of bulls

Dry Run
secret : [1,1,2,3]
guess : [0,1,1,1]
nums : [0,0,0,0,0,0,0,0,0,0]
___indx: 0 1 2 3 4 5 6 7 8 9

for (i =0) secret[i] != guess[i];
nums: [-1,1,0,0,0,0,0,0,0,0]

for( i = 1) secret[i] == gues[i] bulls++;
for(i = 2) sectret [i] != bulls[i];
nums[1] > 0 cow++
nums: [-1,0,1,0,0,0,0,0,0,0]

and so on

Complexity
Time complexity:
O(N);

Space complexity:
O(N)
*/
//Code
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls =0 , cows = 0;
         vector<int> nums(10, 0);

         for(int i=0; i<n; i++){
               int s = secret[i]-'0';
               int g = guess[i]-'0';

               if(s == g) bulls++;
               else{
                   if(nums[s] < 0) cows++;
                   if(nums[g] > 0) cows++;

                   nums[s]++;
                   nums[g]--;
               }
         }
         return to_string(bulls)+ 'A'+to_string(cows)+'B';
    }
};
