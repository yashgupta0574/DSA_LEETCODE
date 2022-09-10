class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        double a=sqrt(1+8*n);
        a-=1;
        a/=2;
        return int(a);
    }
};