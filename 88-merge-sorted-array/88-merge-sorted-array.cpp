class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            int p1 = 0, p2 = 0;
            vector<int>numss1(m+n);
            for (int i = 0; i <m+n; i++)
            {
                if (p1 == m) numss1[i] = nums2[p2++];
                else if (p2 == n) numss1[i] = nums1[p1++];
                else if (nums1[p1] <= nums2[p2]) numss1[i] = nums1[p1++];
                else numss1[i] = nums2[p2++];
            }
           nums1=numss1;
        }
};