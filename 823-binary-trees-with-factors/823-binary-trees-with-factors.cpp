class Solution
{
    public:
        int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int> mp;
        long long int ans=0;
        for (int i = 0; i < n; i++) mp[arr[i]]=1;
        vector<int> dp(n + 1, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] != 0) continue;
                if (mp.find(arr[i] / arr[j]) != mp.end()) mp[arr[i]]=(mp[arr[i]]+mp[arr[j]]*mp[arr[i]/arr[j]])%mod;
            }
            ans=(ans+mp[arr[i]])%mod;
        }
        return ans;
    }
};