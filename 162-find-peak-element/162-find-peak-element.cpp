class Solution
{
    public:
        int mid, ans1;
    int bS(vector<int> &nums, int i, int n)
    {
        if (i == n && (nums[i] <= nums[i + 1] || nums[i] <= nums[i - 1])) return -1;
        mid = (i + n) / 2;
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
        ans1 = bS(nums, i, mid);
        if (ans1 == -1) return bS(nums, mid + 1, n);
        return ans1;
    }

    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size(), i = 0;
        if(n==1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        return bS(nums, i, n);
    }
};