class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            mp[nums[i]]++;
            mp[stoi(s)]++;
        }
        return mp.size();
    }
};