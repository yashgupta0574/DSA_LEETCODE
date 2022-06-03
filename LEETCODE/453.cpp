#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int ans = 0, n = nums.size(), minm = INT_MAX;
        for (int i = 0; i < n; i++)
            if (nums[i] < minm)
                minm = min(minm, nums[i]);
        for (int i = 0; i < n; i++)
            ans += nums[i] - minm;
        return ans;
    }
};