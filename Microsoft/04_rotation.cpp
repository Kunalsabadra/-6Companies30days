//Approach
/*
lets consider array [4 , 3,2,6]
  now [4 , 3,2,6] f(0) = 0*4+1*3+2*2+3*6  = 25
  now [6,4,3,2] f(1) = 0*6+1*4+2*3+3*2    = 16
  ..
  ..
  [3 , 2, 6 , 4]  f(3) = 0*3+1*2+2*6+3*4 = 26
  
  From above observations we get
    f(1) = f(0) + sum -N*array[last_element_of_rotated_array]
    where sum = sum of all elemnets of array
          N = length oif array
          
          f(k) = f(k-1)+ sum - N*(array [N - K])
          
        Time complexity: O(n)
         Space complexity: O(1)
     we solve it using 1D dp array
 */

//Code
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
          int n = nums.size();
          if(n == 0) return 0;
        int sum =0;
        int f0 = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
           f0 += i*nums[i];
        }
        int maxi = INT_MIN;
        vector<int> prev(n);
        prev[0] = f0;
        maxi = prev[0];
        for(int i=1; i<n; i++){
            prev[i] = prev[i-1]+sum-n *nums[n-i];
            maxi = max(maxi , prev[i]);
        }
        return maxi;
    }
};
