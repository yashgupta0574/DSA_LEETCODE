class Solution
{
    public:
        vector<int> findErrorNums(vector<int> &nums)
        {
            int n = nums.size(), x, y;
            vector<int> v(n + 1, 0);
            for (int i = 0; i < n; i++)
            {
                if (v[nums[i]] != 0) x = nums[i];
                v[nums[i]]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (v[i] == 0)
                {
                    y = i;
                    break;
                }
            }
            return {
                x,
                y
            };
        }
};