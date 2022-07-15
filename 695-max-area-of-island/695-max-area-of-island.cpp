class Solution
{
    public:
        int m, n, curr = 0, ans = 0;
    vector<vector < bool>> vis;

    void calc(vector<vector < int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1 || vis[i][j] == true) return;
        curr++;
        vis[i][j] = true;
        ans = max(ans, curr);
        calc(grid, i + 1, j);
        calc(grid, i - 1, j);
        calc(grid, i, j + 1);
        calc(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector < int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        vis = vector<vector < bool>> (m, vector<bool> (n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    curr = 0;
                    calc(grid, i, j);
                }
            }
        }
        return ans;
    }
};