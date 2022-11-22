class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>v(n+1,INT_MAX);
        v[0]=0;
        v[1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++) v[i]=min(v[i],v[i-j*j]+1);
        }
        return v[n];
    }
};