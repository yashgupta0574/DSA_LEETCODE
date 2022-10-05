class Solution
{
    public:
        vector<vector < int>> ans;
    map<vector < int>, int> mp;
    int target,n;

    void dosum(vector<int> &candidates, vector<int> member, int idx, int currsum)
    {
        if (currsum > target || idx==n) return;
        if (currsum == target)
        {
            if (mp.find(member) == mp.end())
            {
                ans.push_back(member);
                mp[member]++;
            }
            return;
        }
        dosum(candidates, member, idx + 1, currsum);
        member.push_back(candidates[idx]);
       	dosum(candidates,member,idx,currsum+candidates[idx]);
        dosum(candidates, member, idx + 1, currsum + candidates[idx]);
    }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        n=candidates.size();
        this->target = target;
        vector<int> member;
        dosum(candidates, member, 0, 0);
        return ans;
    }
};