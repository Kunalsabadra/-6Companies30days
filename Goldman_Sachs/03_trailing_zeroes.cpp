//code
class Solution {
public:

int fact(int n){
    if(n == 0 or n == 1) return 1;
    return   n*fact(n-1);
}
    int trailingZeroes(int n) {
        int cnt=0;
        while(n){
            n/=5;
            cnt+=n;
        }
        return cnt;
    }
};
