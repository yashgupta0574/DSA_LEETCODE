class Solution
{
    public:
        static bool cc(vector<int> &v1, vector<int> &v2)
        {
            if (v1[0] == v2[0]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        }
    int direction(vector<int> &a, vector<int> &b, vector< int > &c)
    {
        return (b[0] - a[0]) *(c[1] - a[1]) - (b[1] - a[1]) *(c[0] - a[0]);
    }
    vector<vector < int>> outerTrees(vector<vector < int>> &trees)
    {
        int n = trees.size();
        if (n <= 3) return trees;
        vector<vector < int>> ans;
        sort(trees.begin(), trees.end(), cc);

        for (int i = 0; i < n; i++)
        {
            while (ans.size() > 1 && direction(ans[ans.size() - 2], ans[ans.size() - 1], trees[i]) < 0) ans.pop_back();
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        for (int i = n-1; i >=0; i--)
        {
            while (ans.size() > 1 && direction(ans[ans.size() - 2], ans[ans.size() - 1], trees[i]) < 0) ans.pop_back();
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        sort(ans.begin(),ans.end(),cc);
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};