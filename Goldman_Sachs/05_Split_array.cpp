class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> mp , m;
        int n = nums.size();
 for(int i=0; i<n; i++){
     mp[nums[i]]++;
 }

        for(auto i:nums){
            if(mp[i] == 0)    continue;
            mp[i]--;
            if(m[i-1] > 0){
                m[i-1]--;
                m[i]++;
            }
            else if(mp[i+1] != 0 and mp[i+2] != 0){
                mp[i+1]--;
                mp[i+2]--;
                m[i+2]++;
            }
            else return false;
        }
        return true;
    }
}; 
