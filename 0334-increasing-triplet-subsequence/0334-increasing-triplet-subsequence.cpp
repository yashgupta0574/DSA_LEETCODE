class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int F = INT_MAX, S = INT_MAX;
        if(nums.size()<3)   return false;
        for(int& num : nums){
            if(num <= F)  F = num;
            else if(num <= S)  S = num;
            else    return true;
        }
        return false;
    }
};