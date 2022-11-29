class Solution
{
    public:
        int minSumOfLengths(vector<int> &arr, int target)
        {
            int n = arr.size(), ans = INT_MAX, st = 0, curr = 0, len = INT_MAX;
            vector<int> v(n, INT_MAX);
            for (int i = 0; i < n; i++)
            {
                curr += arr[i];
                while (curr > target && st < i)
                {
                    curr -= arr[st];
                    st++;
                }
                if (curr == target)
                {
                    if (st!=0 && v[st - 1] != INT_MAX) ans = min(ans, v[st - 1] + i - st + 1);
                    len = min(len, i - st + 1);
                }
                v[i] = len;
            }
            return ans==INT_MAX?-1:ans;
        }
};