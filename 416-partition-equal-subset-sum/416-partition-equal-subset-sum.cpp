class Solution
{
    public:
        int n, sm;
    vector<vector<int>>dp;
    bool check(vector<int> &nums, int i,int t)
    {
        if (i == n)
        {
            if(t==0) return true;
            return false;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        if(t>=nums[i] && check(nums,i+1,t-nums[i])) return dp[i][t]=true;  
        return dp[i][t]=check(nums,i+1,t);
    }

    bool canPartition(vector<int> &nums)
    {
        n = nums.size(), sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += nums[i];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        if (sm % 2) return false;
        dp=vector<vector<int>>(n,vector<int>(sm/2+1,-1));
        return check(nums, 0,sm/2);
    }
};