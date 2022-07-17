class Solution
{
    public:
        int mod = 1000000007;
    int kInversePairs(int n, int k)
    {
        if (k > n *(n - 1) / 2) return 0;
        int dp[n + 4][k + 4];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i < n + 1; i++) dp[i][0] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                if (j - i >= 0) dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
            }
        }

        return dp[n][k];
    }
};