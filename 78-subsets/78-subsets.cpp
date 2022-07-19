class Solution
{
    public:
        vector<int> nums;
    int sz;
    vector<vector < int>> ans;
    map<vector < int>, bool> mp;
    void solve(vector<int> &n, int idx)
    {
        if (idx == sz)
        {
            if (!mp[n]) ans.push_back(n);
            mp[n] = true;
            return;
        }
        for (int i = idx; i < sz; i++)
        {
            n.push_back(nums[i]);
            solve(n, i + 1);
            n.pop_back();
            solve(n, i + 1);
        }
    }

    vector<vector < int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        sz = nums.size();
        vector<int> n;
        solve(n, 0);
        return ans;
    }
};