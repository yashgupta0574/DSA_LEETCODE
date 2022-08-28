class Solution
{
    public:
        vector<vector < int>> diagonalSort(vector<vector < int>> &mat)
        {
            int n = mat.size(), m = mat[0].size(), x, y;
            priority_queue<int, vector < int>, greater < int>> pq;
            for (int i = 0; i < m; i++)
            {
                x = i, y = 0;
                while (x < m && y < n)
                {
                    pq.push(mat[y][x]);
                    x++;
                    y++;
                }
                x = i, y = 0;
                while (x < m && y < n)
                {
                    mat[y][x] = pq.top();
                    pq.pop();
                    x++;
                    y++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                x = 0, y = i;
                while (x < m && y < n)
                {
                    pq.push(mat[y][x]);
                    x++;
                    y++;
                }
                x = 0, y = i;
                while (x < m && y < n)
                {
                    mat[y][x] = pq.top();
                    pq.pop();
                    x++;
                    y++;
                }
            }
            return mat;
        }
};