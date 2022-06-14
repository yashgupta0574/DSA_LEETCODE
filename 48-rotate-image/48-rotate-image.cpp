class Solution
{
    public:
        int n;
    void transpose(vector<vector < int>> &matrix)
    {
        n = matrix.size();
        for (int i = 0; i < n ;i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i<=j)
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector < int>> &matrix)
    {
        transpose(matrix);
       	for (int i = 0; i < n; i++)
       	{
       	    for (int j = 0; j < n / 2; j++)
       	    {
       	        swap(matrix[i][j], matrix[i][n - j - 1]);
       	    }
       	}
    }
};