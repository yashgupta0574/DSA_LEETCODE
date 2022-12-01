class Solution
{
    public:

        int maxProductPath(vector<vector < int>> &grid)
        {
            int m = grid.size(), n = grid[0].size(), MOD = 1e9 + 7;
            long long dp[m][n][2];	// 0- minimum product 1- maximum product
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 and j == 0)
                    {
                        dp[0][0][0] = dp[0][0][1] = grid[0][0];
                    }
                    else if (i == 0)
                    {
                    	// filling columns
                        dp[0][j][0] = dp[0][j][1] = dp[0][j - 1][0] *grid[0][j];
                    }
                    else if (j == 0)
                    {
                    	// filling rows
                        dp[i][0][0] = dp[i][0][1] = dp[i - 1][0][0] *grid[i][0];
                    }
                    else if (grid[i][j] < 0)
                    {
                        dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) *grid[i][j];
                        dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) *grid[i][j];
                    }
                    else
                    {
                        dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) *grid[i][j];
                        dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) *grid[i][j];
                    }
                }
            }
            int ans = max(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]) % MOD;
            return ans < 0 ? -1 : ans;
        }
};