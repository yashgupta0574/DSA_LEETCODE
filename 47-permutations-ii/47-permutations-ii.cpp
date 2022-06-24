class Solution
{
    public:
        vector<vector < int>> ans;
    int n;
    void calc(vector<int> nums, int idx)
    {
        if (idx == n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            calc(nums, idx + 1);
            //swap(nums[i], nums[i-1]);
        }
    }
    vector<vector < int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        calc(nums, 0);
        return ans;
    }
};