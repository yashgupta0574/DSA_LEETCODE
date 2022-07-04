class Solution
{
    public:
        int candy(vector<int> &ratings)
        {
            int n = ratings.size(), i = 1, ans = 1, curr = 0,temp=0;
            while (i < n)
            {
                curr = 1;
                temp=INT_MAX;
                while (i < n && ratings[i] > ratings[i - 1])
                {
                    curr += 1;
                    ans += curr;
                    i++;
                    temp=curr;
                }
                if(curr!=1) curr = 0;
                while (i < n && ratings[i] < ratings[i - 1])
                {
                    curr += 1;
                    ans += curr;
                    i++;
                }
                if(curr>=temp) ans+=(curr-temp+1);
                if(curr!=1) curr = 1;
                while (i < n && ratings[i] == ratings[i - 1])
                {
                    ans += curr;
                    i++;
                }
            }
            return ans;
        }
};