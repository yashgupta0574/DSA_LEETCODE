class Solution
{
    public:
        int subarraysDivByK(vector<int> &nums, int k)
        {
            int n = nums.size(), ans = 0, rem = 0;
            unordered_map<int, int> m;
            m[0] = 1;
            rem = ((nums[0] % k) + k) % k;
            ans += m[rem];
            m[rem]++;
            for (int i = 1; i < n; i++)
            {
                nums[i] += nums[i - 1];
                rem = ((nums[i] % k) + k) % k;
                ans += m[rem];
                m[rem]++;
            }
            return ans;
        }
};