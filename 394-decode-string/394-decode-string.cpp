class Solution
{
    public:
        string decodeString(string s)
        {
            int n = s.length(), i = 0, val = 0;
            if (n == 1) return s;
            stack<string> st;
            stack<int> num;
            string temp, res, ans;
            while (i < n)
            {
                temp = "";
                res = "";
                while (i < n && s[i] >= '0' && s[i] <= '9') temp += s[i++];
                if (temp != "") num.push(stoi(temp));
                if (i < n && s[i] == '[')
                {
                    st.push("[");
                    i++;
                }
                while (i < n && s[i] >= 'a' && s[i] <= 'z')
                {
                    res += s[i];
                    i++;
                }
                if (res != "") st.push(res);
                res = "";
                if (i < n && s[i] == ']')
                {
                    stack<string> rev;
                    while (st.top() != "[")
                    {
                        rev.push(st.top());
                        st.pop();
                    }
                    while (!rev.empty())
                    {
                        res += rev.top();
                        rev.pop();
                    }
                    st.pop();
                    val = num.top();
                    num.pop();
                    string add;
                    while (val--) add += res;
                    st.push(add);
                    i++;
                }
            }
            stack<string> sub;
            while (!st.empty())
            {
                sub.push(st.top());
                st.pop();
            }
            while (!sub.empty())
            {
                ans += sub.top();
                sub.pop();
            }
            return ans;
        }
};