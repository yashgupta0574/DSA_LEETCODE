class Solution
{
    public:
        vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
        {
            vector<string> ans;
            int n1 = words1.size(), n2 = words2.size(), sz, k, sz1, l, temp;
            vector<int> m(26, 0);
            for (k = 0; k < n2; k++)
            {
                vector<int> a(26, 0);
                sz1 = words2[k].length();
                for (l = 0; l < sz1; l++)
                {
                    a[words2[k][l] - 'a']++;
                    m[words2[k][l] - 'a'] = max(m[words2[k][l] - 'a'], a[words2[k][l] - 'a']);
                }
            }
            for (int i = 0; i < n1; i++)
            {
                vector<int> m1(26, 0);
                sz = words1[i].length();
                for (int j = 0; j < sz; j++) m1[words1[i][j] - 'a']++;
                for (temp = 0; temp < 26; temp++)
                {
                    if (m1[temp] < m[temp]) break;
                }
                if (temp == 26) ans.push_back(words1[i]);
            }
            return ans;
        }
};