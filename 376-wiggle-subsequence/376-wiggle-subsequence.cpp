class Solution
{
    public:
        int wiggleMaxLength(vector<int> &nums)
        {
            int n = nums.size(), ans = 1, c, i = 0;
            while (i < n && nums[i] == nums[0]) i++;
            if (i == n) return 1;
            else
            {
                if (nums[i] < nums[0]) c = 0;
                else c = 1;
                ans++;
                i++;
            }
            while (i < n)
            {
                if (nums[i] < nums[i - 1] && c == 1)
                {
                    ans++;
                    c = 0;
                }
                else if (nums[i] > nums[i - 1] && c == 0)
                {
                    ans++;
                    c=1;
                }
                i++;
            }
            return ans;
        }
};