class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            int n = nums.size(), i = 0;
            vector<int>::iterator it;
            while (i < nums.size())
            {
                int j = i + 1;
                it = nums.begin() + i;
                while (j < nums.size() && nums[j] == nums[i]) j++;
                if (j - i > 1)
                {
                    nums.erase(it + 1, it + j - i);
                }
                i++;
            }
            return nums.size();
        }
};