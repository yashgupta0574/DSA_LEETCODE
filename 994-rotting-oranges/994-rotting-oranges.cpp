class Solution
{
    public:
        int orangesRotting(vector<vector < int>> &grid)
        {
            int n = grid.size(), m = grid[0].size();
            queue<pair<int, int>> q;
            int ans = 0, x, y;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 2) q.push({ i,
                        j });
                }
            }
            q.push({ -1,
                -1 });
            pair<int, int> p;
            while (!q.empty())
            {
                p = q.front();
                q.pop();
                x = p.first, y = p.second;
                if (x == -1)
                {
                    if (q.empty()) break;
                    ans++;
                    q.push({ -1,
                        -1 });
                }
                else
                {
                    if (x + 1 < n && y < m && grid[x + 1][y] == 1)
                    {
                        q.push({ x + 1,
                            y });
                        grid[x + 1][y] = 2;
                    }
                    if (x - 1 >= 0 && y < m && grid[x - 1][y] == 1)
                    {
                        q.push({ x - 1,
                            y });
                        grid[x - 1][y] = 2;
                    }
                    if (x < n && y + 1 < m && grid[x][y + 1] == 1)
                    {
                        q.push({ x,
                            y + 1 });
                        grid[x][y + 1] = 2;
                    }
                    if (x < n && y - 1 >= 0 && grid[x][y - 1] == 1)
                    {
                        q.push({ x,
                            y - 1 });
                        grid[x][y - 1] = 2;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1) return -1;
                }
            }
            return ans;
        }
};