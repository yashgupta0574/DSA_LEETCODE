class Solution
{
    public:
        int ans = 0, n;
    int dp[1002][1002][2];
    int calc(vector<int> &prices, int k, int bs, int idx)
    {
        if (idx == n)
        {
            return 0;
        }
        if(k<0) return 0;
        if(dp[idx][k][bs]!=-1) return dp[idx][k][bs];
        int mx=INT_MIN;
        if (bs == 1)
        {
            mx = max(mx,prices[idx]+ calc(prices, k, !bs, idx + 1));
        }
        else
        {
            mx=max(mx,-prices[idx]+calc(prices, k - 1, !bs, idx + 1));
        }
        mx=max(mx,calc(prices, k, bs, idx + 1));
        return dp[idx][k][bs]=mx;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return calc(prices, k, 0, 0);
    }
};