class Solution {
public:
      int reverse(int MyNum){
  int RevNum = 0;
  int remainder;

  while(MyNum > 0){
    remainder = MyNum % 10;
    MyNum = MyNum / 10;
    RevNum = RevNum * 10 + remainder;
  }
  return RevNum;
}

  
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mp;
        int cnt = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++){
            int rev = reverse(nums[i]);
            int diff = nums[i] - rev;
            if(mp.count(diff) == true){
                // cnt += mp[diff]%mod;
                cnt = (cnt+mp[diff])%mod;
            }
            mp[diff]++;
        }
        return cnt;
    }
};
