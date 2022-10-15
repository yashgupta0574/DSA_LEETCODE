class Solution
{
    public:
        int n, K;
    vector<vector < int>> dp;

    int compress(string s, int idx, int k)
    {
        if (s.length() - idx <= k) return 0;
        if (dp[idx][k] != -1)
        {
            return dp[idx][k];
        }
        int K = k;
        int res = k ? compress(s, idx + 1, k - 1) : 10000, c = 1;
        for (int i = idx + 1; i <= s.size(); i++)
        {
            res = min(res, compress(s, i, k) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 : 0))));
            if (i == s.size()) break;
            if (s[i] == s[idx]) ++c;
            else if (--k < 0) break;
        }
        return dp[idx][K] = res;
    }

    int getLengthOfOptimalCompression(string s, int k)
    {
        n = s.length();
        this->K = k;
        dp = vector<vector < int>> (n + 5, vector<int> (k + 5, -1));
        return compress(s, 0, k);
    }
};
