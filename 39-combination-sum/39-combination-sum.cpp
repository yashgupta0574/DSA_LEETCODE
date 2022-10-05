class Solution
{
    public:
        vector<vector < int>> ans;
    int target, n;

    void dosum(vector<int> &candidates, vector<int> member, int idx, int currsum)
    {
        if (currsum > target || idx == n) return;
        if (currsum == target)
        {
            ans.push_back(member);
            return;
        }
        member.push_back(candidates[idx]);
        dosum(candidates, member, idx, currsum + candidates[idx]);
        member.pop_back();
        dosum(candidates, member, idx + 1, currsum);
    }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();
        this->target = target;
        vector<int> member;
        dosum(candidates, member, 0, 0);
        return ans;
    }
};