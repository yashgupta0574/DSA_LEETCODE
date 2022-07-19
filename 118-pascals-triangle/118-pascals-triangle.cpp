class Solution
{
    public:
        vector<vector < int>> generate(int numRows)
        {
            vector<vector < int>> ans;
            ans.push_back({ 1 });
            if (numRows == 1) return ans;
            int prev = 0, curr = 0, cnt = 1,sz;
            numRows--;
            while (cnt != numRows+1)
            {
                sz = ans[cnt - 1].size();
                prev = 0, curr = 0;
                vector<int> res;
                for (int i = 0; i < sz; i++)
                {
                    prev = curr;
                    curr = ans[cnt - 1][i];
                    res.push_back(prev + curr);
                }
                res.push_back(1);
                ans.push_back(res);
                cnt++;
            }
            return ans;
        }
};