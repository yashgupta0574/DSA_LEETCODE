class Solution
{
    public:
        string reverseWords(string s)
        {
            int n = s.length(), i = 0;
            stack<string> st;
            string ans = "";
            while (i < n)
            {
                while (i < n && s[i] == ' ') i++;
                string temp = "";
                if (i == n) break;
                while (i < n && s[i] != ' ') temp += s[i++];
                st.push(temp);
            }
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
                if (!st.empty()) ans += ' ';
            }
            return ans;
        }
};