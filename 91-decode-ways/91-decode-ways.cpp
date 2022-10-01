class Solution
{
    public:
        int numDecodings(string s)
        {
            int n = s.length();
            vector<int> dp(n + 1, 1);
            if (s[0] == '0') return 0;
            dp[0] = 1;
            if (s[1] == '0' && (s[0] >= '3' || s[0]=='0')) return 0;
            else if(s[1]=='0' && (s[0]=='2' || s[0]=='1')) dp[1]=1;
            else if ((s[0] == '2' && s[1] <= '6') || s[0] == '1') dp[1] = 2;
            for (int i = 2; i < n; i++)
            {
                if (s[i] == '0' && (s[i - 1] >= '3' || s[i-1]=='0')) return 0;
                if(s[i]=='0' && (s[i-1]=='2' || s[i-1]=='1')) dp[i]=dp[i-2];
                else if ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1') dp[i] = dp[i - 2] + dp[i - 1];
                else dp[i] = dp[i - 1];
            }
            return dp[n - 1];
        }
};