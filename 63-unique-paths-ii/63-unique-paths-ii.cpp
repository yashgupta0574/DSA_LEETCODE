class Solution
{
    public:
        int m, n;
    vector<vector < int>> dp;
    int ways(int i, int j, vector<vector < int>> &ob)
    {
        if (i == m - 1 && j == n - 1) return 1;
        if (i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (ob[i][j] == 1) return 0;
        return dp[i][j] = ways(i + 1, j, ob) + ways(i, j + 1, ob);
    }

    int uniquePathsWithObstacles(vector<vector < int>> &obstacleGrid)
    {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        dp = vector<vector < int>> (m + 1, vector<int> (n + 1, -1));
        return ways(0, 0, obstacleGrid);
    }
};