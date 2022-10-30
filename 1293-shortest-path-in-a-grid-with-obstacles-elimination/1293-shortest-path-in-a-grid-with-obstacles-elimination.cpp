class Solution
{
    public:
        int m, n;
    vector<vector < bool>> vis;
    vector<vector<vector< int>>> dp;
    int dfs(vector<vector < int>> &grid, int i, int j, int k)
    {
        if (i >= m || j >= n || i < 0 || j < 0 || vis[i][j]) return 1e5;
        else if (dp[i][j][k] != -1) return dp[i][j][k];
        else if (i == 0 && j == 0) return dp[i][j][k] = 0;
        if (grid[i][j])
        {
            if (k == 0) return dp[i][j][k] = 1e5;
            else k--;
        }
        vis[i][j] = true;
        int t = dfs(grid, i - 1, j, k);
        int l = dfs(grid, i, j - 1, k);
        int d = dfs(grid, i + 1, j, k);
        int r = dfs(grid, i, j + 1, k);
        vis[i][j] = false;
        return dp[i][j][k] = 1 + min(t, min(l, min(r, d)));
    }

    int shortestPath(vector<vector < int>> &grid, int k)
    {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector < bool>> (m + 1, vector<bool> (n + 1, false));
        dp = vector<vector<vector< int>>> (m + 1, vector<vector < int>> (n + 1, vector<int> (k + 1, -1)));
        int ans = dfs(grid, m - 1, n - 1, k);
        if (ans >= m *n) return -1;
        return ans;
    }
};