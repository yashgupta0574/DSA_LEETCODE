class Solution
{
    public:
        int longestSubsequence(vector<int> &arr, int diff)
        {
            unordered_map<int, pair<int, int>> mp;
            int n = arr.size(), ans = 1;
            if (diff == 0)
            {
                unordered_map<int, int> mp;
                for (int i = 0; i < n; i++)
                {
                    mp[arr[i]]++;
                    ans = max(ans, mp[arr[i]]);
                }
                return ans;
            }
            for (int i = 0; i < n; i++)
            {
               	//if (mp.find(arr[i]) == mp.end())
                {
                    mp[arr[i]].first = 1;
                    mp[arr[i]].second = i;
                }
                if (mp.find(arr[i] - diff) != mp.end() && mp[arr[i] - diff].second != i && mp[arr[i]].first == 1)
                {
                    mp[arr[i]].first += mp[arr[i] - diff].first;
                    ans = max(ans, mp[arr[i]].first);
                   	//cout << i << " " << ans << endl;
                }
            }
            return ans;
        }
};