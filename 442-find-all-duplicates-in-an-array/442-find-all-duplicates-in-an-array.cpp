class Solution
{
    public:
        vector<int> findDuplicates(vector<int> &nums)
        {
            vector<int> ans;
            int n = nums.size();
            unordered_map<int, int> m;
            for (int i = 0; i < n; i++)
                m[nums[i]]++;
            for (int i = 0; i < n; i++)
            {
                if (m[nums[i]] == 2)
                {
                    ans.push_back(nums[i]);
                    m[nums[i]] = -1;
                }
            }
            return ans;
        }
};