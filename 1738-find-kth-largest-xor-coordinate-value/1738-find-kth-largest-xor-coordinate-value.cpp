class Solution
{
    public:
        int kthLargestValue(vector<vector < int>> &matrix, int k)
        {
            int n = matrix.size(), m = matrix[0].size();
            vector<int> v;
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < m; j++) matrix[i][j] ^= matrix[i - 1][j];
            }
            for (int i = 0; i < n; i++) v.push_back(matrix[i][0]);
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    matrix[i][j] ^= matrix[i][j - 1];
                    v.push_back(matrix[i][j]);
                }
            }
            sort(v.begin(), v.end());
            return v[m *n - k];
        }
};