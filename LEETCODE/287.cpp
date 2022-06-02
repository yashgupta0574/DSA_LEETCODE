#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> a(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            if (!a[nums[i]])
                a[nums[i]] = true;
            else
                return nums[i];
        }
        return n + 1;
    }
};