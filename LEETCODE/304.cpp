#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> Matrix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        Matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 == 0 && col1 != 0)
            return Matrix[row2][col2] - Matrix[row2][col1 - 1];
        if (col1 == 0 && row1 != 0)
            return Matrix[row2][col2] - Matrix[row1 - 1][col2];
        if (row1 == 0 && col1 == 0)
            return Matrix[row2][col2];
        return Matrix[row2][col2] - Matrix[row2][col1 - 1] - Matrix[row1 - 1][col2] + Matrix[row1 - 1][col1 - 1];
    }
};
