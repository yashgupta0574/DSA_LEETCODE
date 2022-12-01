class Solution
{
    public:
        int mod = 1e9 + 7;

    long long int modPow(long long int x, long long int y)
    {
        if (y == 0) return 1;
        long long int p = modPow(x, y / 2) % mod;
        p = (p *p) % mod;
        return y % 2 ? (x *p) % mod : p;
    }

    int minNonZeroProduct(int P)
    {
        if (P == 1) return 1;
        long long int p = P;
        long long int mask = (1ULL << p) - 1, ans = mask;
        mask--;
        mask %= mod;
        ans %= mod;
        return (ans* modPow(mask, ((1ULL << p) - 1) / 2)) % mod;
    }
};