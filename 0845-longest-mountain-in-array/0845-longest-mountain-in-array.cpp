class Solution
{
    public:
        int longestMountain(vector<int> &arr)
        {
            int n = arr.size(), ans = 0, i = 1;
            while (i < n)
            {
                int len = 0;
                bool flag=false;
                while (i<n && arr[i] > arr[i - 1]) 
                {
                    flag=true;
                    len++;
                    i++;
                }
                while(i<n && arr[i]<arr[i-1] && flag)
                {
                    len++;
                    i++;
                    ans=max(ans,len);
                }
                if(!flag) i++;
            }
            if(ans==0) return 0;
            return ans+1;
        }
};