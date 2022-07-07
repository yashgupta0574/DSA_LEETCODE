class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            int n = nums.size(), ans = INT_MIN;
            if(n==1) return 1;
            vector<int> dp(n + 1, 1);
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i]) dp[i] = max(dp[i], 1 + dp[j]);
                }
                ans=max(ans,dp[i]);
            }
            return ans;
        }
};