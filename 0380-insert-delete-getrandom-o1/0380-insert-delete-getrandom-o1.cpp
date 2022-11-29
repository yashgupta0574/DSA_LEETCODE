class RandomizedSet
{
    public:
        set<int> s;
    set<int>::iterator it;
    RandomizedSet() {}

    bool insert(int val)
    {
        if (s.find(val) == s.end())
        {
            s.insert(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (s.find(val) == s.end()) return false;
        s.erase(s.find(val));
        return true;
    }

    int getRandom()
    {
        int val=rand()%s.size();
        it=s.begin();
        while(val--) it++;
        return *it;
    }
};

/**
 *Your RandomizedSet object will be instantiated and called as such:
 *RandomizedSet* obj = new RandomizedSet();
 *bool param_1 = obj->insert(val);
 *bool param_2 = obj->remove(val);
 *int param_3 = obj->getRandom();
 */