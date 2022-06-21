class Solution
{
    public:
        vector<vector < int>> ans;
    int n;
    map<vector < int>, int> m;
    void subsets(vector<int> &nums, vector<int> a, int idx)
    {
        if (idx == n)
        {
            if (m.find(a) == m.end())
            {
                ans.push_back(a);
                m[a]++;
            }
            return;
        }
            a.push_back(nums[idx]);
            vector<int>::iterator it = a.end();
            it--;
            subsets(nums, a, idx + 1);
            a.erase(it);
            subsets(nums, a, idx + 1);
    }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> a;
        subsets(nums, a, 0);
        return ans;
    }
};