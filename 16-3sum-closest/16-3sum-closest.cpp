class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int ans = INT_MAX, diff = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    if (abs(target - (nums[i] + nums[j] + nums[k])) < diff)
                    {
                        ans = nums[i] + nums[j] + nums[k];
                        diff = abs(target - (nums[i] + nums[j] + nums[k]));
                    }
                    if (nums[i] + nums[j] + nums[k] > target) k--;
                    else j++;
                }
            }
            return ans;
        }
};