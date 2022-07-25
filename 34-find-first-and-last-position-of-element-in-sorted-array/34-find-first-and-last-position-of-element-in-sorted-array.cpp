class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int n = nums.size(), i = 0, j = n - 1, mid = (i + j) / 2;
            if (n == 0) return { -1,
                -1 };
            while (i < j && nums[mid] != target)
            {
                if (target < nums[mid]) j = mid - 1;
                else i = mid + 1;
                mid = (i + j) / 2;
            }
            int temp = mid, x = -1, y = -1;
            if (nums[mid] != target) return {
                x,
                y
            };
            while (temp >= 0 && nums[temp] == target) temp--;
            x = temp + 1;
            while (mid < n && nums[mid] == target) mid++;
            y = mid - 1;
            return {
                x,
                y
            };
        }
};