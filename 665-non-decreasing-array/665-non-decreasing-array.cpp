class Solution
{
    public:
        bool checkPossibility(vector<int> &nums)
        {
            int n = nums.size(), cnt = 0, temp;
            if (n == 1) return true;
            if (nums[1] < nums[0]) cnt++;
            bool check1 = true, check2 = true;
            for (int i = 2; i < n; i++)
            {
                if (nums[i] < nums[i - 1] and cnt == 1) return false;
                else if (nums[i] < nums[i - 1])
                {
                    cnt++;
                    temp = nums[i - 1];
                    nums[i - 1] = nums[i - 2];
                    if (i + 1 < n && nums[i + 1] < nums[i] || nums[i] < nums[i - 1]) check1 = false;
                    nums[i - 1] = temp;
                    temp = nums[i];
                    nums[i] = nums[i - 1];
                    if (i + 1 < n && nums[i + 1] < nums[i]) check2 = false;
                    nums[i] = temp;
                    if (!check1 and!check2) return false;
                    else if (check2 == false and check1 == true) nums[i - 1] = nums[i - 2];
                    else if (check2 == true and check1 == false) nums[i] = nums[i - 1];
                    check1 = check2 = true;
                }
            }
            return true;
        }
};