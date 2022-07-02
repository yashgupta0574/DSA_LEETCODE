class Solution
{
    public:
        int mod = 1000000007;
    int mult(int hmx, int vmx)
    {
        long long int ans = 0;
        while (vmx)
        {
            if (vmx &1 == 1) ans = (ans + hmx) % mod;
            hmx = (hmx *2) % mod;
            vmx /= 2;
        }
        return ans;
    }
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        int n = horizontalCuts.size(), m = verticalCuts.size(), hmx, vmx;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        hmx = horizontalCuts[0];
        vmx = verticalCuts[0];
        for (int i = 1; i < n; i++) hmx = max(hmx, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < m; i++) vmx = max(vmx, verticalCuts[i] - verticalCuts[i - 1]);
        hmx = max(hmx, h - horizontalCuts[n - 1]);
        vmx = max(vmx, w - verticalCuts[m - 1]);
        return mult(hmx, vmx);
    }
};