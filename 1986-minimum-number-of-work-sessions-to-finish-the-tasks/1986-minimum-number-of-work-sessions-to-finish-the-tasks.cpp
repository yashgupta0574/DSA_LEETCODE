class Solution
{
    public:
        int n, sess;
    vector<vector < int>> dp;
    int calc(vector<int> &tasks, int mask, int sum)
    {
        if (mask == 0) return 0;
        if (dp[mask][sum] != -1) return dp[mask][sum];
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1<<i))
            {
                if (sum + tasks[i] <= sess) ans = min(ans, calc(tasks, (mask ^ (1 << i)), sum + tasks[i]));
                else ans = min(ans, 1 + calc(tasks, (mask ^ (1 << i)), tasks[i]));
            }
        }
        return dp[mask][sum] = ans;
    }
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        n = tasks.size();
        sess = sessionTime;
        dp = vector<vector < int>> (1 <<n, vector<int> (sessionTime + 1, -1));
        int mask = (1 << n) - 1;
        return calc(tasks, mask, 0) + 1;
    }
};