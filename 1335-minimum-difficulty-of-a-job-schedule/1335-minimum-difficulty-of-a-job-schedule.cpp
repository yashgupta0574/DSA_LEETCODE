class Solution
{
    public:
        int n;
    vector<vector < int>> dp;
    int calc(vector<int> &v, int idx, int d)
    {
        if(d == 1) return *max_element(begin(v)+idx, end(v));
        if (dp[idx][d] != -1) return dp[idx][d];
        int mx = INT_MIN, result = INT_MAX;
        for (int i = idx; i <= n - d; i++)
        {
            mx = max(mx, v[i]);
            result = min(result, mx + calc(v, i + 1, d - 1));
        }
        return dp[idx][d] = result;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        n = jobDifficulty.size();
        if (n < d) return -1;
        dp = vector<vector < int>> (n + 1, vector<int> (d + 1, -1));
        return calc(jobDifficulty, 0, d);
    }
};