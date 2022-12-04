class Solution
{
    public:
        vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r)
        {
            int n = nums.size(), m = l.size();
            vector<bool> ans;
            for (int i = 0; i < m; i++)
            {
                vector<int> temp;
                copy(nums.begin() + l[i], nums.begin() + r[i]+1, back_inserter(temp));
                sort(temp.begin(), temp.end());
                bool ar = true;
                for (int i = 1; i < temp.size(); i++)
                {
                    if (temp[i] - temp[i - 1] != temp[1] - temp[0]) ar = false;
                }
                ans.push_back(ar);
            }
            return ans;
        }
};