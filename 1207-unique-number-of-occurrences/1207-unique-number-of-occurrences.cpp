class Solution
{
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            int n = arr.size();
            unordered_map<int, int> mp, mp1;
            for (int i = 0; i < n; i++) mp[arr[i]]++;
            for (auto it: mp)
            {
                if (mp1.find(it.second) != mp1.end()) return false;
                mp1[it.second]++;
            }
            return true;
        }
};