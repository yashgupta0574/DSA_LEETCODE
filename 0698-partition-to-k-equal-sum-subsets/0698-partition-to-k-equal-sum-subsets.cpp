class Solution
{
    public:
        int sum, n;
    vector<bool> vis;
    bool calc(vector<int> &nums, int k, int i, int curr)
    {
        if (k == 1) return true;
        if (i >= n) return false;
        if (curr == sum) return calc(nums, k - 1, 0, 0);
        for (int idx = i; idx <= n - 1; idx++)
        {
            if (vis[idx] || curr + nums[idx] > sum) continue;
            vis[idx] = true;
            if (calc(nums, k, idx + 1, curr + nums[idx])) return true;
            vis[idx] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int mx = 0;
        sum = 0;
        n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
        if (sum % k || mx > sum / k || n<k) return false;
        sum /= k;
        vis = vector<bool> (n, false);
        return calc(nums, k, 0, 0);
    }
};