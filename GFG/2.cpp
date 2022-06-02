// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        for (int i = 0; i < n; i++) // Transpose of the matrix
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        for (int i = 0; i < n; i++) //  After transposing, reverse the columns
        {
            int low = 0, high = n - 1;
            while (low < high)
            {
                swap(matrix[low][i], matrix[high][i]);
                low++;
                high--;
            }
        }
    }
};