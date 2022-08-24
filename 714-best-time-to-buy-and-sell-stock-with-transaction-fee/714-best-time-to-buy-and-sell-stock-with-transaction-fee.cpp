class Solution
{
    public:
    vector<vector<int>>dp;
    int n,f;
        int calc(vector<int> &prices,int idx,int buy)
        {
            if(idx==n) return 0;
            if(dp[idx][buy]!=-1) return dp[idx][buy];
            if(buy) return dp[idx][buy]=max(-prices[idx]+calc(prices,idx+1,0),calc(prices,idx+1,1));
            return dp[idx][buy]=max(prices[idx]-f+calc(prices,idx+1,1),calc(prices,idx+1,0));
        }
    
        int maxProfit(vector<int> &prices, int fee)
        {
            n = prices.size();
            f=fee;
            dp=vector<vector<int>>(n,vector<int>(2,-1));
            return calc(prices,0,1);
        }
};