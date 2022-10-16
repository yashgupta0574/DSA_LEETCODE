class Solution
{
    public:
        int mx, t;
    int dp[1 << 21];

    int f(int val, int k)
    {
        if (val >= t) return 0;
        if (dp[k] != -1) return dp[k];

        for (int i = 1; i <= mx; i++)
        {
            if (!(k &(1 << i)) && !f(val + i, k + (1 << i))) return dp[k] = 1;
        }
        return dp[k] = 0;
    }

    bool canIWin(int mx, int t)
    {
        this->mx = mx;
        this->t = t;
        memset(dp, -1, sizeof dp);
        if (t < 2) return 1;
        if (mx *(mx + 1) / 2 < t) return 0;
        return f(0, 0);
    }
};