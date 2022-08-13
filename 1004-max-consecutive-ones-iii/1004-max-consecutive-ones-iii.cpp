class Solution
{
    public:
        int longestOnes(vector<int> &nums, int k)
        {
            int n = nums.size(), ans = 0, z = 0, st = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0) z++;
                while (z > k)
                {
                    if (nums[st] == 0) z--;
                    st++;
                }
                ans = max(ans, i - st + 1);
            }
            return ans;
        }
};