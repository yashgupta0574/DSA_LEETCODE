class TimeMap
{
    public:
        map<string, map<int, string>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (mp[key].find(timestamp) != mp[key].end()) return mp[key][timestamp];
        auto it = mp[key].upper_bound(timestamp);
        if (it == mp[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 *Your TimeMap object will be instantiated and called as such:
 *TimeMap* obj = new TimeMap();
 *obj->set(key,value,timestamp);
 *string param_2 = obj->get(key,timestamp);
 */
