class Solution {
public:
    int n;
    vector<int>dp;
    int count(vector<int>& nums,int idx)
    {
       if(idx>=n) return 0;
       if(dp[idx]!=-1) return dp[idx]; 
       dp[idx]=max(count(nums,idx+1),count(nums,idx+2)+nums[idx]);
       return dp[idx];
    }
    
    int rob(vector<int>& nums) {
        n=nums.size();
        dp=vector<int>(n+1,-1);
        return count(nums,0);
    }
};