class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {
            int n = nums.size();
            vector<long long int> fw(n, 0), bw(n + 1, 0);
            fw[0] = nums[0];
            for (int i = 1; i < n; i++) fw[i] += (fw[i - 1] + nums[i]);
            bw[n - 1] = nums[n - 1];
            bw[n] = 0;
            for (int i = n - 2; i >= 0; i--) bw[i] += (bw[i + 1] + nums[i]);
            int ans = INT_MAX, val = INT_MAX;
            for (int i = 0; i < n-1; i++)
            {
                int now = abs(round(fw[i] / (i + 1)) - round(bw[i + 1] / (n - i - 1)));
                if (val > now)
                {
                    val = now;
                    ans = i;
                }
            }
            if(val>round(fw[n-1]/n)) ans=n-1;
            return ans;
        }
};