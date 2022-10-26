class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
            int n = nums.size(), prefix = 0;
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                prefix += nums[i];
                prefix %= k;
                if (prefix == 0 && i > 0) return true;
                if (mp.find(prefix) != mp.end() && (i - mp[prefix]) > 1) return true;
                if (mp.find(prefix) == mp.end()) mp[prefix] = i;
            }
            return false;
        }
};