class Solution
{
    public:
        bool checkIfPangram(string sentence)
        {
            int n = sentence.length();
            vector<bool> v(n, false);
            for (int i = 0; i < n; i++)
            {
                v[sentence[i] - 'a'] = true;
            }
            for (int i = 0; i < 26; i++)
            {
                if (v[i] == false) return false;
            }
            return true;
        }
};