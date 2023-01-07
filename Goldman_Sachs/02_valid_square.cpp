//code
#include<set>
class Solution {
     int ds(vector<int> &a , vector<int> &b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    } 
    
    
public:
     
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        s.insert(ds(p1,p2));
        s.insert(ds(p1,p3));
        s.insert(ds(p1,p4));
        s.insert(ds(p2,p3));
        s.insert(ds(p2,p4));
        s.insert(ds(p3,p4));
        return (!s.count(0)) and (s.size() == 2);
    }
};
