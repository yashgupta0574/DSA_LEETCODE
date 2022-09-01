class Solution
{
    public:
        int n, m;
    vector<vector < int>> dp;
    bool check(string &s, string &p, int i, int j)
    {
        if (i == n && j == m) return true;
        if (i == n && j < m)
        {
            for (int idx = j; idx < m; idx++)
            {
                if (p[idx] != '*') return false;
            }
            return true;
        }
        if (i >= n || j >= m) return false;
        if (dp[i][j] != -1) return dp[i][j];
        if (p[j] != '?' && p[j] != '*')
        {
            if (p[j] != s[i]) return dp[i][j] = false;
            else return dp[i][j] = check(s, p, i + 1, j + 1);
        }
        if (p[j] == '?') return dp[i][j] = check(s, p, i + 1, j + 1);
        return dp[i][j] = check(s, p, i, j + 1) || check(s, p, i + 1, j + 1) || check(s, p, i + 1, j);
    }

    bool isMatch(string s, string p)
    {
        n = s.length(), m = p.length();
        dp = vector<vector < int>> (n, vector<int> (m, -1));
        return check(s, p, 0, 0);
    }
};