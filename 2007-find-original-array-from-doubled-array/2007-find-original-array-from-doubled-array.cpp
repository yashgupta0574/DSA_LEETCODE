class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &changed)
        {
            int n = changed.size();
            if (n == 1 || n % 2 == 1) return {};
            unordered_map<int, int> mp;
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                mp[changed[i]]++;
            }
            sort(changed.begin(), changed.end());
            for (int i = 0; i < n; i++)
            {
                if (mp.find(changed[i]) == mp.end()) continue;
                mp[changed[i]]--;
                if (mp[changed[i]] == 0) mp.erase(changed[i]);
                if (changed[i] % 2 == 0)
                {
                    if (mp.find(changed[i] / 2) != mp.end())
                    {
                        mp[changed[i] / 2]--;
                        if (mp[changed[i] / 2] == 0) mp.erase(changed[i] / 2);
                        ans.push_back(changed[i] / 2);
                    }
                    else if (mp.find(changed[i] *2) != mp.end())
                    {
                        mp[changed[i] *2]--;
                        if (mp[changed[i] *2] == 0) mp.erase(changed[i] *2);
                        ans.push_back(changed[i]);
                    }
                    else
                    {
                        ans.push_back(changed[i]);
                    }
                }
                else
                {
                    if (mp.find(changed[i] *2) != mp.end())
                    {
                        mp[changed[i] *2]--;
                        if (mp[changed[i] *2] == 0) mp.erase(changed[i] *2);
                        ans.push_back(changed[i]);
                    }
                    else
                    {
                        return {};
                    }
                }
            }
            if (ans.size() != n / 2) return {};
            return ans;
        }
};