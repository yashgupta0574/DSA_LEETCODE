class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size(), b = 0, s = 0, ans = 0, st = 0;
            if(n==1) return 0;
            while (st+1<n && prices[st] >= prices[st + 1])
            {
                st++;
            }
            b = prices[st];
            if (prices[0] < prices[1]) b = prices[0];
            for (int i = 1; i < n - 1; i++)
            {
                if (prices[i] > prices[i - 1] && prices[i] >= prices[i + 1])
                {
                    s = prices[i];
                    ans += (s - b);
                    //cout<<ans<<" ";
                    s = 0;
                    while(i+2<n && prices[i+2]<=prices[i+1]){
                        i++;
                    }
                    b = prices[i + 1];
                    i++;
                }
            }
            if (s == 0 and prices[n - 1] > prices[n - 2])
            {
                s = prices[n - 1];
                ans += (s - b);
            }
            return ans;
        }
};