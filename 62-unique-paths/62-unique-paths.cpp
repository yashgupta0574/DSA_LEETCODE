class Solution
{
    public:
        vector<vector < int>> dp;;
    int calc(int m, int n)
    {
        if (m < 0 || n < 0) return 0;
        if(dp[m][n]!=0) return dp[m][n];
        dp[m][n] = calc(m - 1, n) + calc(m, n - 1);
        return dp[m][n];
    }

    int uniquePaths(int m, int n)
    {
        dp = vector<vector < int>> (m+1, vector<int> (n+1, 0));
        dp[0][0]=1;
        dp[1][1]=2;
        dp[0][1]=1;
        dp[1][0]=1;
        return calc(m - 1, n - 1);
    }
};