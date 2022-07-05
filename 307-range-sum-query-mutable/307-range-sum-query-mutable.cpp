class NumArray
{
    public:
        vector<int> st;
    vector<int> arr;
    int n;
    void build(int node, int i, int j)
    {
        if (i == j)
        {
            st[node] = arr[i];
            return;
        }
        int mid = (i + j) / 2;
        build(2 *node, i, mid);
        build(2 *node + 1, mid + 1, j);
        st[node] = st[2 *node] + st[2 *node + 1];
    }

    void update(int node, int i, int j, int idx, int val)
    {
        if (i == j)
        {
            st[node] = val;
            arr[i] = val;
            return;
        }
        int mid = (i + j) / 2;
        if (idx <= mid)
        {
            update(2 *node, i, mid, idx, val);
        }
        else
        {
            update(2 *node + 1, mid + 1, j, idx, val);
        }
        st[node] = st[2 *node] + st[2 *node + 1];
    }

    int query(int node, int i, int j, int left, int right)
    {
        if (i > right || j < left)
        {
            return 0;
        }
        if (i >= left && j <= right)
        {
            return st[node];
        }
        int mid = (i + j) / 2;
        int q1 = query(2 *node, i, mid, left, right);
        int q2 = query(2 *node + 1, mid + 1, j, left, right);
        return q1 + q2;
    }

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        arr = nums;
        st.resize(4 *n, 0);
        build(1, 0, n - 1);
    }

    void update(int index, int val)
    {
        update(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *obj->update(index,val);
 *int param_2 = obj->sumRange(left,right);
 */