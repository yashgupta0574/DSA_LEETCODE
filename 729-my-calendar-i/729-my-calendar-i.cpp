class MyCalendar
{
    public:
        set<pair<int, int>> s;
    MyCalendar()
    {
       	//Have a good day stalkers!!
    }

    bool book(int start, int end)
    {
        for (auto it: s)
        {
            if (start >= it.second || end <= it.first) continue;
            return false;
        }
        s.insert({ start,
            end });
        return true;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */