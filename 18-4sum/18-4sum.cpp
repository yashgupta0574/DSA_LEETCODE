class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            int n = nums.size(), i = 0, j = n - 1, k, l;
            long long int sum,sum1,sum2;
            vector<vector < int>> ans;
            sort(nums.begin(), nums.end());
            map<vector < int>, int> m;
            for (int i = 0; i < n - 3;i++)
            {
                for (int j = n - 1; j >= i + 3; j--)
                {
                    k = i + 1;
                    l = j - 1;
                    sum=nums[i]+nums[j];
                    while (k < l)
                    {
                        sum1=nums[k]+nums[l];
                        sum2=sum+sum1;
                        if (sum2== target && m.find({ nums[i],
                                nums[k],
                                nums[l],
                                nums[j] }) == m.end())
                        {
                            ans.push_back({ nums[i],
                                nums[k],
                                nums[l],
                                nums[j] });
                            m[
                            {
                                nums[i],
                                nums[k],
                                nums[l],
                                nums[j]
                            }]++;
                            k++;
                            l--;
                        }
                        else if (sum2 < target) k++;
                        else l--;
                    }
                }
            }

            return ans;
        }
};