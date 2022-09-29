class Solution
{
    public:

        static bool cc(pair<int, int> p1, pair<int, int> p2)
        {
            if (p1.first != p2.first) return p1.first < p2.first;
            return p1.second < p2.second;
        }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({abs(arr[i] - x), arr[i]});
        }
        sort(v.begin(), v.end(), cc);
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(v[i].second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};