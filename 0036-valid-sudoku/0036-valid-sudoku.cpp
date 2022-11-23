class Solution
{
    public:
        bool issafe(vector<vector < char>> &grid, int row, int col, int num)
        {
            for (int i = 0; i < 9; i++)
            {
                if (grid[row][i] - '0' == num && i != col) return false;
            }
            for (int i = 0; i < 9; i++)
            {
                if (grid[i][col] - '0' == num && i != row) return false;
            }
            int rowstart = row - row % 3;
            int colstart = col - col % 3;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (i + rowstart == row && j + colstart == col) continue;
                    if (grid[i + rowstart][j + colstart] - '0' == num) return false;
                }
            }
            return true;
        }
    bool solveSudoku(vector<vector < char>> &board, int row, int col)
    {
        if (row == 8 && col == 9) return true;
        if (col == 9)
        {
            col = 0;
            row++;
        }
        if (board[row][col] == '.') return solveSudoku(board, row, col + 1);

        if (issafe(board, row, col, board[row][col] - '0'))
        {
            if (solveSudoku(board, row, col + 1)) return true;
        }
        return false;
    }

    bool isValidSudoku(vector<vector < char>> &board)
    {
        return solveSudoku(board, 0, 0);
    }
};