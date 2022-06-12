class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> &nums)
        {
            int curr = 0, mx = 0, n = nums.size(), st = 0;
            unordered_map<int, int> m;
            if (n == 1) return nums[0];
            vector<int> a(n, 0);
            a[0] = nums[0];
            m[nums[0]]=-1;
            for (int i = 1; i < n; i++)
            {
                m[nums[i]]=-1;
                a[i] = nums[i] + a[i - 1];
            }
            for (int i = 0; i < n; i++)
            {
                if (st == 0 && m[nums[i]]==-1)
                {
                    curr += nums[i];
                    mx = max(mx, curr);
                    m[nums[i]] = i;
                }
                else if (m[nums[i]] >= st)
                {
                    curr = a[i] - a[m[nums[i]]];
                    mx = max(mx, curr);
                    st = m[nums[i]] + 1;
                    m[nums[i]] = i;
                }
                else
                {
                    curr += nums[i];
                    mx = max(mx, curr);
                    m[nums[i]] = i;
                }
            }
            return mx;
        }
};