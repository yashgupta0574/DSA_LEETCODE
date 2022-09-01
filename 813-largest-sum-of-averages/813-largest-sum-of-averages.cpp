class Solution
{
    public:
        double solve(int i, int j, vector<int> &arr, int part, vector<vector< double>> &dp)
        {
            if (i > j) return 0.0;
            if (part == 0) return (double(arr[j] - arr[i - 1])) / double(j - i + 1);
            if (dp[i][part] != -1) return dp[i][part];
            double score = 0;
            for (int k = i; k <= j; k++)
            {
                double curr = (double(arr[k] - arr[i - 1])) / double(k - i + 1) +
                    solve(k + 1, j, arr, part - 1, dp);
                score = max(score, curr);
            }
            return dp[i][part] = score;
        }
    double largestSumOfAverages(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<vector < double>> dp(n + 1, vector<double> (k, -1));
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < n; i++) arr[i + 1] = nums[i] + arr[i];
        return solve(1, n, arr, k - 1, dp);
    }
};
