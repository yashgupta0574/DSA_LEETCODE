class Solution
{
    public:
        vector<vector < int>> dp;
    int k, n, mod = 1e9 + 7;
    int calc(int idx, int suml)
    {
        if(idx==n && suml==0) return 1;
        if (idx == n || (idx < n - 1 && suml <= 0)) return 0;
        if (dp[idx][suml] != -1) return dp[idx][suml];
        int temp = 0, i = 1;
        for (i = 1; i <= k; i++)
        {
            if (suml < i) break;
            temp = (temp + calc(idx + 1, suml - i)) % mod;
        }
        return dp[idx][suml] = (temp) % mod;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        if (target < n) return 0;
        this->k = k;
        this->n = n;
        dp = vector<vector < int>> (n + 1, vector<int> (target + 1, -1));
        return calc(0, target);
    }
};