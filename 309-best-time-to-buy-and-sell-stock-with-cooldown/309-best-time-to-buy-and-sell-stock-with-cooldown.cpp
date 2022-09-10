class Solution {
public:
    int n;
    int dp[5002][2];
    int calc(vector<int> &prices, int bs, int idx)
    {
        if (idx >= n)
        {
            return 0;
        }
        if(dp[idx][bs]!=-1) return dp[idx][bs];
        int mx=INT_MIN;
        if (bs == 1)
        {
            mx = max(mx,prices[idx]+ calc(prices, !bs, idx + 2));
        }
        else
        {
            mx=max(mx,-prices[idx]+calc(prices, !bs, idx + 1));
        }
        mx=max(mx,calc(prices, bs, idx + 1));
        return dp[idx][bs]=mx;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return calc(prices, 0, 0);
    }
};
