#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, Target;
    vector<vector<int>> ans;
    vector<int> a;
    void combinationSum(int i, int sum, vector<int> &candidates)
    {
        if (sum == Target)
        {
            ans.push_back(a);
        }
        else if (sum > Target)
            return;
        else
        {
            while (i < n)
            {
                a.push_back(candidates[i]);
                combinationSum(i + 1, sum + candidates[i], candidates);
                a.pop_back();
                while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                    i++;
                i++;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        Target = target;
        combinationSum(0, 0, candidates);
        return ans;
    }
};