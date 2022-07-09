class Solution
{
    public:
        void gameOfLife(vector<vector < int>> &board)
        {
            int m = board.size(), n = board[0].size(), c, calc;
            vector<vector < int>> ans = board;
            int dx[8] = { 0,
                0,
                1,
                1,
                1,
                -1,
                -1,
                -1
            };
            int dy[8] = { 1,
                -1,
                0,
                1,
                -1,
                0,
                1,
                -1
            };
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    calc = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        if (j + dx[k] >= 0 && j + dx[k] < n && i + dy[k] >= 0 && i + dy[k] < m)
                            calc += ans[i + dy[k]][j + dx[k]];
                    }
                    if (ans[i][j] == 1 && calc < 2) board[i][j] = 0;
                    else if (ans[i][j] == 1 && (calc == 2 || calc == 3)) board[i][j] = 1;
                    else if (ans[i][j] == 1 && calc > 3) board[i][j] = 0;
                    else if (ans[i][j] == 0 && calc == 3) board[i][j] = 1;
                }
            }
        }
};