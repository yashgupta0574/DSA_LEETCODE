class Solution
{
    public:
        vector<vector < string>> ans;
    int n;
    string check;
    bool palindrome(int i, int j)
    {
        while (i <= j)
        {
            if (check[i] != check[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void calc(vector<string> &res, int idx)
    {
        if (idx == n)
        {
            ans.push_back(res);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            if (palindrome(idx, i))
            {
                res.push_back(check.substr(idx, i - idx + 1));
                calc(res, i + 1);
                res.pop_back();
            }
        }
    }

    vector<vector < string>> partition(string s)
    {
        n = s.length();
        this->check = s;
        vector<string> res;
        calc(res, 0);
        return ans;
    }
};