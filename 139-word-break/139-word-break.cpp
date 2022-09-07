class Solution
{
    public:
        bool wordBreak(string s, vector<string> &wordDict)
        {
            int n = s.length();
            vector<int>dp(n+1,0);
            dp[0] = 1;
            for (int i = 1; i <= n; i++)
                for (auto ss: wordDict)
                {
                    int m = ss.length();
                    if (i - m >= 0 && dp[i - m] && s.substr(i - m, m) == ss) dp[i] = 1;
                }
            return dp[n];
        }
};