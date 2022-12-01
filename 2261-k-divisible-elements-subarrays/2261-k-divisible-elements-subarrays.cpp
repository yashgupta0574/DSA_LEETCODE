class Solution
{
    public:
        int countDistinct(vector<int> &nums, int k, int p)
        {
            set<pair<string,int>> st;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                string s;
                for (int j = i; j < n; j++)
                {
                    if (nums[j] % p == 0) cnt++;
                    if (cnt > k) break;
                    s += to_string(nums[j]);
                    s+='a';
                    st.insert({s,j-i+1});
                }
            }
            return st.size();
        }
};