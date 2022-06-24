class Solution
{
    public:
        vector<vector < int>> dp;
    int calc(int m, int n, vector<vector < int>> &grid)
    {
        if (m == 0 && n == 0) return grid[m][n];
        else if ((m == 1 && n == 0) || (m == 0 && n == 1)) return grid[m][n] + grid[0][0];
        if (m < 0 || n < 0) return INT_MAX;
        if (dp[m][n] != 0) return dp[m][n];
        dp[m][n] = grid[m][n] + min(calc(m - 1, n, grid), calc(m, n - 1, grid));
        return dp[m][n];
    }
    
    int minPathSum(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector < int>> (m, vector<int> (n, 0));
        return calc(m - 1, n - 1, grid);
    }
};