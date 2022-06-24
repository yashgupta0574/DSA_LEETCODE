class Solution
{
    public:
        vector<vector < int>> ans;
    int n;
    void calc(vector<int>nums, int idx)
    {
        if (idx == n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            swap(nums[i], nums[idx]);
            calc(nums, idx + 1);
        }
    }
    vector<vector < int>> permute(vector<int> &nums)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        calc(nums, 0);
        return ans;
    }
};