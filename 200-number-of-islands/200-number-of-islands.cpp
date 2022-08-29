class Solution
{
    public:
        vector<vector < int>> color;
    int m, n, ans;
    void colorize(vector<vector < char>> &grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || color[i][j] == 1) return;
        color[i][j] = 1;
        colorize(grid, i + 1, j);
        colorize(grid, i - 1, j);
        colorize(grid, i, j + 1);
        colorize(grid, i, j - 1);
    }
    int numIslands(vector<vector < char>> &grid)
    {
        m = grid.size(), n = grid[0].size(), ans = 0;
        color = vector<vector < int>> (m, vector<int> (n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && color[i][j] == 0)
                {
                    colorize(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};