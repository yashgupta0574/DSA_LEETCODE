class Solution
{
    public:
        int jump(vector<int> &nums)
        {
            int n = nums.size(), ans = 1;
            vector<int> dp(n + 1, INT_MAX-1);
            for(int i=1;i<min(nums[0],n);i++) dp[i]=1;
            dp[0]=0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (j + nums[j] >= i) dp[i] = min(dp[i], dp[j]+1);
                }
            }
            return dp[n - 1];
        }
};