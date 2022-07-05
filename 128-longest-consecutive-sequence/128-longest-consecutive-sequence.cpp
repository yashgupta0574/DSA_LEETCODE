class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            map<int, int> m;
            int n = nums.size(), c = 0, ans = 1, curr = 1;
            if (n == 0 || n == 1) return n;
            for (int i = 0; i < n; i++) m[nums[i]]++;
            map<int, int>::iterator it = m.begin();
            c = it->first;
            it++;
            while (it != m.end())
            {
                if (it->first - c == 1)
                {
                    curr++;
                    ans = max(ans, curr);
                }
                else curr = 1;
                c = it->first;
                it++;
            }
            return ans;
        }
};