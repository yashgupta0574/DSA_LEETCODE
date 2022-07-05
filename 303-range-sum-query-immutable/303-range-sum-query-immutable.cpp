class NumArray {
public:
    vector<int>numss;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        numss=nums;
        for(int i=1;i<n;i++) numss[i]+=numss[i-1];
    }
    
    int sumRange(int left, int right) {
        if(left==0) return numss[right];
        return numss[right]-numss[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */