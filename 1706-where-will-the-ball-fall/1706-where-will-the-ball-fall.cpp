class Solution
{
    public:
        int n, m;
    int calc(vector<vector < int>> &grid, int j)
    {
        int c1, c2, i = 0;
        while (i < n && j < m)
        {
            c1 = grid[i][j];
            if (c1 > 0)
            {
                if (j + 1 == m) return -1;
                c2 = grid[i][j + 1];
            }
            else
            {
                if (j - 1 < 0) return -1;
                c2 = grid[i][j - 1];
            }
            if (c1 + c2 == 0) return -1;
            else if (c1 + c2 > 0) j++;
            else j--;
            i++;
        }
        if (i != n) return -1;
        return j;
    }

    vector<int> findBall(vector<vector < int>> &grid)
    {
        vector<int> ans;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            if (i == 0 && grid[0][i] == -1) ans.push_back(-1);
            else if (i == m - 1 && grid[0][i] == 1) ans.push_back(-1);
            else ans.push_back(calc(grid, i));
        }
        return ans;
    }
};