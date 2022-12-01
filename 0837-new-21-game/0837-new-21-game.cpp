class Solution
{
    public:
    double new21Game(int n, int k, int maxPts)
    {
        if(k==0 || n>=k+maxPts) return 1;
        double dp[k+maxPts+1];
        for (int i = 0; i < k+maxPts+1; i++) dp[i] = 0;
        dp[0] = 1.0;
        double ans = 0,window=0;
        int i=0,j=0;
        while(j<=n)
        {
            if(j<k) window+=dp[j++];
            else ans+=dp[j++];
            if(j-i>maxPts) window-=dp[i++];
            dp[j]=window/maxPts;
            
        }
        return ans;
    }
};