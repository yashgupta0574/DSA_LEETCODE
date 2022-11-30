class Solution
{
    public:
        vector < long long > kthPalindrome(vector<int> &queries, int intLength)
        {
            vector < long long > ans;
            int n = queries.size();
            long long int tmp = pow(10, intLength % 2 == 0 ? (intLength / 2 - 1): intLength / 2),value;
            string start, end, complete;
            for (int i = 0; i < n; i++)
            {
                value=tmp;
                value += (queries[i] - 1);
                start = to_string(value);
                end = start;
                reverse(end.begin(), end.end());
                if (intLength % 2 == 0) complete = start + end;
                else complete = start + end.substr(1);
                if (complete.size() == intLength) ans.push_back(stoll(complete));
                else ans.push_back(-1);
            }
            return ans;
        }
};