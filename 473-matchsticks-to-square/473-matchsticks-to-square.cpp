class Solution
{
    public:
        int n, target, a = 0, b = 0, c = 0, d = 0;
    bool rec(vector<int> &m, int idx)
    {
        if (idx == n)
        {
            if (a ==0 && b==0 && c==0 && d==0) return true;
            return false;
        }
        
        if (a >= m[idx])
        {
            a -= m[idx];
            if (rec(m, idx + 1)) return true;
            a += m[idx];
        }
        if (b >= m[idx])
        {
            b -= m[idx];
            if (rec(m, idx + 1)) return true;
            b += m[idx];
        }
        if (c >= m[idx])
        {
            c -= m[idx];
            if (rec(m, idx + 1)) return true;
            c += m[idx];
        }
        if (d >= m[idx])
        {
            d -= m[idx];
            if (rec(m, idx + 1)) return true;
            d += m[idx];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        target = sum / 4;
        a = target;
        b=a;
        c=a;
        d=c;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return rec(matchsticks, 0);
    }
};