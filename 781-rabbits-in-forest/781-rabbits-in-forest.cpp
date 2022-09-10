class Solution
{
    public:
        int numRabbits(vector<int> &answers)
        {
            int n = answers.size(),ans=0;
            unordered_map<int,int>mp;
            for (int i = 0; i < n; i++)
            {
                mp[answers[i]]++;
            }
            for (auto it: mp)
            {
                while (it.second > 0)
                {
                    if (it.second >= it.first+1)
                    {
                        ans += (it.first);
                        it.second -= it.first+1;
                        ans++;
                    }
                    else
                    {
                        ans += it.first;
                        it.second = 0;
                        ans++;
                    }
                }
            }
            return ans;
        }
};