class StockSpanner
{
    public:
        StockSpanner() {}
    stack<int> s;
    int ans = 1;
    bool check = false;
    int next(int price)
    {
        if (s.empty())
        {
            s.push(price);
            return 1;
        }
        ans=1;
        while (!s.empty() && s.top() <= price)
        {
            if (s.top() < 0)
            {
                ans += abs(s.top());
            }
            else
            {
                ans++;
            }
            s.pop();
            check = true;
        }
        if (check)
        {
            s.push(-(ans - 1));
        }
        check = false;
        s.push(price);
        return ans;
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */