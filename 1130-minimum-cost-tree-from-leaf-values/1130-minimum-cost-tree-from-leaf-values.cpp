class Solution
{
    public:
        vector<vector < int>> dp;
    int calc(vector<int> &v, int i, int j)
    {
        if (i > j) return INT_MAX;
        else if (i == j) return 0;
        if (dp[i][j]) return dp[i][j];
        int sum = INT_MAX;
        for (int x = i; x < j; x++)
        {
            sum = min(sum, (*max_element(v.begin() + i, v.begin() + x + 1)) * (*max_element(v.begin() + x + 1, v.begin() + j + 1)) + calc(v, i, x) + calc(v, x + 1, j));
        }
        dp[i][j] = sum;
        return sum;
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        dp = vector<vector < int>> (n, vector<int> (n, 0));
        calc(arr, 0, n - 1);
        return dp[0][n - 1];
    }
};
