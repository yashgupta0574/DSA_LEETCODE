class Solution
{
    public:
        int n;
    vector<int> dp;

    int calc(int idx, vector<int> &cost)
    {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        dp[idx] = cost[idx] + min(calc(idx + 1, cost), calc(idx + 2,cost));
        return dp[idx];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        n = cost.size();
        dp = vector<int> (n, -1);
        calc(0,cost);
        return min(dp[0],dp[1]);
    }
};