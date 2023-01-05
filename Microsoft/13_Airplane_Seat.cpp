//Explanation
/* the nth person will have only two option at the end either to seat on his own seat or 
on the seat one which are likely to happen equally
*/
//code
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1.00000;
        else return 0.50000;
    }
};
