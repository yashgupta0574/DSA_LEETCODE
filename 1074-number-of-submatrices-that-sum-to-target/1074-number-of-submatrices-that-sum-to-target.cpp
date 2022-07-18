class Solution
{
    public:
        int numSubmatrixSumTarget(vector<vector < int>> &matrix, int target)
        {
            int m = matrix.size(), n = matrix[0].size();
            vector<vector < int>> v(m+1,vector<int>(n,0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++) v[i+1][j] = v[i][j]+matrix[i][j];
            }
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = i+1; j <= m; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        int check = 0;
                        for (int l = k; l < n; l++)
                        {
                            check += (v[j][l] - v[i][l]);
                            if (check == target) ans++;
                        }
                    }
                }
            }
            return ans;
        }
};