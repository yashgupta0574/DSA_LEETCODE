class Solution
{
    public:
        int n, m;

    void dfs(vector<vector < char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O') return;
        grid[i][j] = 'Y';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
    void dfs1(vector<vector < char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O') return;
        grid[i][j] = 'X';
        dfs1(grid, i + 1, j);
        dfs1(grid, i, j + 1);
        dfs1(grid, i - 1, j);
        dfs1(grid, i, j - 1);
    }

    void solve(vector<vector < char>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 'O') dfs(grid, i, 0);
            if (grid[i][m - 1] == 'O') dfs(grid, i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 'O') dfs(grid, 0, i);
            if (grid[n - 1][i] == 'O') dfs(grid, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'O') dfs1(grid, i, j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'Y') grid[i][j]='O';
            }
        }
    }
};