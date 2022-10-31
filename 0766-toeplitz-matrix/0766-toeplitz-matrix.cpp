class Solution
{
    public:
        bool isToeplitzMatrix(vector<vector < int>> &matrix)
        {
            int n = matrix.size(), m = matrix[0].size(), i = 0, val, j, k;
            while (i < m)
            {
                val = matrix[0][i], j = i, k = 0;
                while (k < n && j < m)
                {
                    if (matrix[k][j] != val) return false;
                    k++;
                    j++;
                }
                i++;
            }
            i = 1;
            while (i < n)
            {
                val = matrix[i][0], j = 0, k = i;
                while (k < n && j < m)
                {
                    if (matrix[k][j] != val) return false;
                    k++;
                    j++;
                }
                i++;
            }
            return true;
        }
};