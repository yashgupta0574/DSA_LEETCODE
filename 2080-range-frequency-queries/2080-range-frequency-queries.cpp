class RangeFreqQuery
{
    public:
        map<int, vector < int>> mp;
    RangeFreqQuery(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
    }

    int query(int left, int right, int value)
    {
        int l = lower_bound(mp[value].begin(), mp[value].end(), left) - mp[value].begin();
        int r = lower_bound(mp[value].begin(), mp[value].end(), right) - mp[value].begin();
        //cout<<l<<" "<<r<<endl;
        if(r==mp[value].size() || mp[value][r]>right) return r-l;
        if(l==mp[value].size()) return 0;
        if(l==r && mp[value][r]>right) return 0; 
        return r - l + 1;
    }
};

/**
 *Your RangeFreqQuery object will be instantiated and called as such:
 *RangeFreqQuery* obj = new RangeFreqQuery(arr);
 *int param_1 = obj->query(left,right,value);
 */