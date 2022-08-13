class Solution
{
    public:
        int integerBreak(int n)
        {
            vector<int> dp(n + 5, 0);
            dp[0] = 0, dp[1] = 1, dp[2] = 1,dp[3]=2;
            if(n<=3) return dp[n];
            for(int i=3;i<=n;i++) dp[i]=i;
            for (int i = 4; i <= n; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    dp[i] = max(dp[i], dp[j] *(i - j));
                }
            }
            return dp[n];
        }
};