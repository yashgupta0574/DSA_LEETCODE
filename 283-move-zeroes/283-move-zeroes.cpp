class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
            int n = nums.size(), i = 0, j = 0;
            while (i < n)
            {
                if (nums[i] != 0)
                {
                    j = i;
                    while (j > 0 && nums[j - 1] == 0)
                    {
                        swap(nums[j], nums[j - 1]);
                        j--;
                    }
                }
                i++;
            }
        }
};