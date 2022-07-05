class Solution
{
    public:
    int n;
        void dfs(int i, int j, vector<vector < int>> &grid)
        {
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || grid[i][j] == 2) return;
            grid[i][j] = 2;
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
        }
    int shortestBridge(vector<vector < int>> &grid)
    {
        n = grid.size();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    flag = true;
                    dfs(i, j, grid);
                    break;
                }
            }
            if (flag) break;
        }
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) v1.push_back({ i,
                    j });
                else if (grid[i][j] == 2) v2.push_back({ i,
                    j });
            }
        }
        int lv1 = v1.size(), lv2 = v2.size(), ans = INT_MAX;
        for (int i = 0; i < lv1; i++)
        {
            for (int j = 0; j < lv2; j++)
            {
                ans = min(ans, abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second) - 1);
            }
            if(ans==1) return ans;
        }

        return ans;
    }
};