class Solution
{
    public:
        int n, m, l;
    vector<vector < int>> dp;
    bool check(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (i == n && j == m && k == l) return true;
        if (i > n || j > m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if (s3[k] != s1[i] && s3[k] != s2[j]) return false;
        if (s3[k] == s1[i] && s3[k] == s2[j]) return dp[i][j] = check(s1, s2, s3, i + 1, j, k + 1) || check(s1, s2, s3, i, j + 1, k + 1);
        else if (s3[k] == s1[i]) return dp[i][j] = check(s1, s2, s3, i + 1, j, k + 1);
        else if (s3[k] == s2[j]) return dp[i][j] = check(s1, s2, s3, i, j + 1, k + 1);
        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        n = s1.length(), m = s2.length(), l = s3.length();
        if (l != n + m) return false;
        dp = vector<vector < int>> (n + 1, vector<int> (m + 1, -1));
        return check(s1, s2, s3, 0, 0, 0);
    }
};