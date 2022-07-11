class Solution
{
    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            int n = grid.size(), ans = 1, ff, ss;
            queue<pair<int, int>> q;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        grid[i][j] = -1;
                        q.push({ i,
                            j });
                    }
                    else grid[i][j] = 201;
                }
            }
            if (q.empty() || q.size() == n *n) return -1;
            int dx[] = { 0,
                0,
                1,
                -1
            };
            int dy[] = { 1,
                -1,
                0,
                0
            };
            pair<int, int> p;
            while (!q.empty())
            {
                int sz = q.size();
                while (sz--)
                {
                    p = q.front();
                    q.pop();
                    ff = p.first;
                    ss = p.second;
                    for (int i = 0; i < 4; i++)
                    {
                        if (ff + dy[i] >= 0 && ff + dy[i] < n && ss + dx[i] >= 0 && ss + dx[i] < n)
                        {
                            if (grid[ff + dy[i]][ss + dx[i]] == -1) continue;
                            else if (grid[ff + dy[i]][ss + dx[i]] > ans)
                            {
                                grid[ff + dy[i]][ss + dx[i]] = ans;
                                q.push({ ff + dy[i],
                                    ss + dx[i] });
                            }
                        }
                    }
                }
                ans++;
            }
            return ans - 2;
        }
};