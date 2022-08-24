class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double val=log10(n)/log10(3);
        int v=val;
        return (val-v)==0;
    }
};