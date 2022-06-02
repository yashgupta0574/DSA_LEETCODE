#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size(), st = 0, end = n - 1, i = 0;
        if (n == 1)
            return;
        if (n == 2)
        {
            if (nums[0] > nums[1])
                swap(nums[0], nums[1]);
            return;
        }
        while (i <= end)
        {
            if (nums[i] == 0)
            {
                if (i > st)
                    swap(nums[i], nums[st++]);
                else
                    i++;
            }
            else if (nums[i] == 2)
                swap(nums[i], nums[end--]);
            if (nums[i] == 1)
                i++;
        }
    }
};