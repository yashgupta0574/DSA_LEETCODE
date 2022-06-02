#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int>::iterator it = nums.begin();
        int i = 0, n = nums.size();
        while (i + 1 < n)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(it + i + 1);
                n--;
            }
            else
                i++;
        }
        return n;
    }
};