class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
            int n = nums.size(), i = 1, j = n - 1;
            sort(nums.begin(), nums.end());
            vector<int> ans;
            ans.push_back(nums[0]);
            while (i < j)
            {
                ans.push_back(nums[j--]);
                if (i < j) ans.push_back(nums[i++]);
            }
            if (i == j) ans.push_back(nums[i]);
            return ans;
        }
};