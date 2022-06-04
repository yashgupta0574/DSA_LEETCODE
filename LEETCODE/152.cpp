#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), ans = nums[0], x = 1, y = 1;
        for (int i = 0; i < n; i++)
        {
            x *= nums[i];
            ans = max(ans, x);
            if (x == 0)
                x = 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            y *= nums[i];
            ans = max(ans, y);
            if (y == 0)
                y = 1;
        }
        return ans;
    }
};