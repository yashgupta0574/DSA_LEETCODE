class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k)
        {
            int n = nums.size(), sum = 0, cnt = 0;
            unordered_map<int,int>m;
            for (int i = 0; i < n; i++){
                sum+=nums[i];
                if(sum==k) cnt++;
                if(m.find(sum-k)!=m.end()) cnt+=m[sum-k];
                m[sum]++;
            }
            return cnt;
        }
};