class Solution
{
    public:
        int numOfSubarrays(vector<int> &arr, int k, int th)
        {
            int n = arr.size(), sm = 0, ans = 0;
            if(k>n) return 0;
            for (int i = 0; i < k; i++) sm += arr[i];
            if (sm / k >= th) ans++;
            for (int i = k; i < n; i++)
            {
                sm -= arr[i - k];
                sm += arr[i];
                if (sm / k >= th) ans++;
            }
            return ans;
        }
};