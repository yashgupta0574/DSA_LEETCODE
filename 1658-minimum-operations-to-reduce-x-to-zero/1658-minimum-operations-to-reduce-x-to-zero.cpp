class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int n = nums.size(), sumall = 0;
            for (int i = 0; i < n; i++)
            {
                sumall += nums[i];
            }
            int find = sumall - x, sum = 0, i = 0, j = 0, mn = INT_MAX;
            if(find<0) return -1;
            while (i < n && j < n)
            {
                if(sum < find) sum += nums[j++];
                while (sum > find) sum -= nums[i++];
                if (sum == find)
                {
                    mn = min(n - j + i, mn);
                    if (j < n) sum += nums[j++];
                }
            }
            if (mn == INT_MAX) return -1;
            else return mn;
        }
};