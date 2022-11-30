class Solution
{
    public:
        int mod = 1e9 + 7, N;
    vector<vector<vector< int>>> dp;
    int calc(int n, int k, bool start)
    {
        if (k == 0) return 1;
        if (n >= N) return 0;
        
        if (dp[n][k][start] != -1) return dp[n][k][start];
        if (start) return dp[n][k][start] = (calc(n + 1, k, !start) + calc(n + 1, k, start))%mod;
        else return dp[n][k][start] = (calc(n, k-1, !start) + calc(n + 1, k, start))%mod;
        return dp[n][k][start];
    }

    int numberOfSets(int n, int k)
    {
        dp = vector<vector<vector< int>>> (n + 1, vector<vector < int>> (k + 1, vector<int> (2, -1)));
        N = n;
        return (calc(1, k, 0) + calc(1, k, 1))%mod;
    }
};