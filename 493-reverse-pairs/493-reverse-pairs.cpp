class Solution
{
    public:
        vector<int> tree;
    int query(int node, int st, int en, int l, int r)
    {
        if (st > r || en < l) return 0;
        if (st >= l && en <= r) return tree[node];
        int mid = (st + en) / 2;
        return query(2 *node + 1, st, mid, l, r) + query(2 *node + 2, mid + 1, en, l, r);
    }

    void update(int node, int st, int en, int pos)
    {
       	if (st == en)
       	{
       	    tree[node] += 1;
       	    return;
       	}
       	int mid = (st + en) / 2;
       	if (pos <= mid) update(2 *node + 1, st, mid, pos);
       	else update(2 *node + 2, mid + 1, en, pos);
       	tree[node] = tree[2 *node + 1] + tree[2 *node + 2];
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        tree = vector<int> (8 *n + 5, 0);
        vector < long long > temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(nums[i]);
            temp.push_back(1LL *2 *nums[i]);
        }
        unordered_map < long long, int> pos;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < 2*n; i++) pos[temp[i]] = i;
        for (int i = n - 1; i >= 0; i--)
        {
            ans += query(0, 0, 2 *n, 0, pos[nums[i]] - 1);
            update(0, 0, 2 *n, pos[1LL *2 *nums[i]]);
        }
        return ans;
    }
};