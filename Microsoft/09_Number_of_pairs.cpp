// Approach
// If we sort the array and find the already sorted subarrays from starting and from ending, then the length of the remaining array will be desired answer.
// We will sort the array and store it in one array
// check from left in original array by comparing to thev sorted array if thier values are different then it is the leftmost index smallest unsorted subarray
// Complexity
// Time complexity : O(nlogn) (because of sorting algorithm)
// Space complexity : O(n)

//Code
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        int i=0,j=n-1;
        
        for(;i<n;i++)
        {
            if(nums[i]!=temp[i])
                break;
        }

        for(;j>=0;j--)
        {
            if(nums[j]!=temp[j])
                break;
        }
        int c=0;
        //finding the total number of elements that are not sorted
        for(int k=i;k<=j;k++)
            c++;
        return c;
    }
};
