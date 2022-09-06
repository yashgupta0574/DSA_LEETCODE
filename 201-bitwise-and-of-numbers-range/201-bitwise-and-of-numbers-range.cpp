class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        if(left==0) return 0;
        if(left==right) return left;
        int a=log2(left),b=log2(right),ans=0;
        while(left>0 and right>0){
            a=log2(left),b=log2(right);
            if(a!=b) break;
            left-=pow(2,a);
            right-=pow(2,a);
            ans+=pow(2,a);
        }
        return ans;
    }
};