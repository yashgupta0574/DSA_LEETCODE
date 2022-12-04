class Solution
{
    public:
        vector<vector < int>> dp;
    int n;
    int calc(int idx, int val, vector<int> &stones)
    {
        if (idx >= n)
        {
            if (val >= 0) return 0;
            return 1e6;
        }
        if (dp[idx][val + 3000] != -1) return dp[idx][val + 3000];
        int a, b;
        a = stones[idx] + calc(idx + 1, val + stones[idx], stones);
        b = -stones[idx] + calc(idx + 1, val - stones[idx], stones);
        return dp[idx][val + 3000] = min(a, b);
    }
    int lastStoneWeightII(vector<int> &stones)
    {
        n = stones.size();
        dp = vector<vector < int>> (n + 1, vector<int> (6001, -1));
        return calc(0, 0, stones);
    }
};