class Solution
{
    public:
        vector<int> mostCompetitive(vector<int> &nums, int k)
        {
            int idx = 0, n = nums.size(), sz = 1;
            if (k == n) return nums;
            stack<int> st;
            st.push(nums[0]);
            bool flag = false;
            for (int i = 1; i < n; i++)
            {
                if (flag)
                {
                    st.push(nums[i]);
                    sz++;
                    continue;
                }
                while (!st.empty() && st.top() > nums[i])
                {
                    if (n - i == k - sz)
                    {
                        break;
                    }
                    st.pop();
                    sz--;
                }
                if (!flag)
                {
                    st.push(nums[i]);
                    sz++;
                }
            }
            while(sz-->k) st.pop();
            vector<int> ans(k, 0);
           	for (int i = k - 1; i >= 0; i--)
           	{
           	    ans[i] = st.top();
           	    st.pop();
           	}
            return ans;
        }
};