class Solution
{
    public:
        bool isPossible(vector<int> &nums)
        {
            unordered_map<int, int> done, mp;
            int n = nums.size();
            for (int i = 0; i < n; i++) mp[nums[i]]++;
            for (int i = 0; i < n; i++)
            {
                if (mp[nums[i]] == 0) continue;
                mp[nums[i]]--;
                if (done[nums[i] - 1] > 0)
                {
                    done[nums[i] - 1]--;
                    done[nums[i]]++;
                }
                else if (mp[nums[i] + 1] > 0 && mp[nums[i] + 2] > 0)
                {
                    mp[nums[i] + 1]--;
                    mp[nums[i] + 2]--;
                    done[nums[i]+2]++;
                }
                else return false;
            }
            return true;
        }
};