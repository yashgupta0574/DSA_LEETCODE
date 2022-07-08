class Solution
{
    public:
        int mod = 1000000007;
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        int left[n], right[n];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] < arr[st.top()]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long int prod = (left[i] *right[i]) % mod;
            prod = (prod *arr[i]) % mod;
            ans = (ans + prod) % mod;
        }
        return ans;
    }
};