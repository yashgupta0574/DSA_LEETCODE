class Solution {
public:
    int n;
    vector<int>tree;
    int query(int node, int st, int en, int l, int r)
   {
    if (st > r || en < l) return 0;
    if (l <= st && en <= r) return tree[node];

    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
   }
 
   void update(int node, int st, int en, int idx, int val)
   {
    if (st == en)
    {
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid) update(2 * node, st, mid, idx, val);
    else update(2 * node + 1, mid + 1, en, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
   }

    vector<int> countSmaller(vector<int>& nums) 
    {
        n=nums.size();
        tree=vector<int>(4*n,0);
        vector<int>ans(n);
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)  
        {
            nums[i]=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin()+1;
            while(mp.find(nums[i])!=mp.end()) nums[i]++;
            mp[nums[i]]++;
            
        }
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=query(1,1,n,1,nums[i]-1);
            update(1,1,n,nums[i],1);
        }
        return ans;
    }
};