class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum=0,n=nums.size(),mn=INT_MIN,ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mn=max(mn,nums[i]);
            sum+=nums[i];
            if(sum<0) sum=0;
            ans=max(ans,sum);
        }
        if(ans==0) return mn;
        return ans;
    }
};