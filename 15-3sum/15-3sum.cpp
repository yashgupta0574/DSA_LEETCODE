class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            vector<vector < int>> ans;
            int n = nums.size(), j, k, sum;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n - 2; i++)
            {
                j = i + 1;
                k = n - 1;
                sum = -nums[i];
                while (i < n - 2 && nums[i + 1] == nums[i]) i++;
                while (j < k)
                {
                    if (nums[j] + nums[k] == sum)
                    {
                        ans.push_back({ nums[i],
                            nums[j],
                            nums[k] });
                        j++;
                        k--;
                    }
                    else if (nums[j] + nums[k] < sum) j++;
                    else k--;
                    while (j > i && j < k && nums[j] == nums[j-1]) j++;
                    while (k+1<n && k> j && nums[k] == nums[k+1]) k--;
                }
            }
            return ans;
        }
};