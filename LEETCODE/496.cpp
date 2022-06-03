#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> h;
        stack<int> s;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n2; i++)
        {
            if (s.empty() || s.top() >= nums2[i])
            {
                s.push(nums2[i]);
            }
            else
            {
                while (!s.empty() && s.top() < nums2[i])
                {
                    h[s.top()] = nums2[i];
                    s.pop();
                }
                s.push(nums2[i]);
            }
        }
        for (int i = 0; i < n1; i++)
        {
            if (h[nums1[i]] > nums1[i])
                nums1[i] = h[nums1[i]];
            else
                nums1[i] = -1;
        }
        return nums1;
    }
};