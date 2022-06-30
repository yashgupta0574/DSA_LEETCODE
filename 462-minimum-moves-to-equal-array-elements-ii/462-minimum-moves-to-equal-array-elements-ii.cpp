class Solution {
public:
    int minMoves2(vector<int>& nums) {
       long long int n=nums.size(),ans1=0,ans2=0;
        if(n==1) return 0;
        if(n==2) return abs(nums[0]-nums[1]);
       sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            ans1+=abs(nums[n/2]-nums[i]);
            ans2+=abs(nums[n/2+1]-nums[i]);
        }
        return min(ans1,ans2);
    }
};