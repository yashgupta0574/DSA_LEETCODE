class Solution
{
    public:
        vector<vector < int>> dp;
    int n,m;
    int calc(vector<int> &nums, vector<int> &mult,int idx,int i,int j)
    {
        if(idx==m || i>j) return 0;
        if(dp[i][idx]!=INT_MIN) return dp[i][idx];
        dp[i][idx]=max(calc(nums,mult,idx+1,i+1,j)+mult[idx]*nums[i],calc(nums,mult,idx+1,i,j-1)+mult[idx]*nums[j]);
        return dp[i][idx];
    }

    int maximumScore(vector<int> &nums, vector<int> &mult)
    {
        n = nums.size();
        m=mult.size();
        dp=vector<vector<int>>(m+1,vector<int>(m+1,INT_MIN));
        return calc(nums,mult,0,0,n-1);
    }
};
