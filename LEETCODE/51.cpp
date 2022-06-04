#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> sols;
    int N;
    bool isSafe(vector<string> &board, int row, int col)
    {
        for (int i = 0; i < N; i++)
        {
            if (board[i][col] == 'Q')
                return false;
            if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q')
                return false;
            if (row - i >= 0 && col + i < N && board[row - i][col + i] == 'Q')
                return false;
        }
        return true;
    }

    void solve(vector<string> &board, int row)
    {
        if (row == N)
        {
            sols.push_back(board);
            return;
        }
        for (int col = 0; col < N; col++)
        {
            if (isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        N = n;
        solve(board, 0);
        return sols;
    }
};