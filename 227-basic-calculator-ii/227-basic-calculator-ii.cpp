class Solution
{
    public:
        int priority(char & c)
        {
            if (c == '/' || c == '*') return 1;
            else return 0;
        }

    int calculate(string s)
    {
        int n = s.length(), op1 = -1, op2 = -1, j = n - 1, i = 0;
        char opr;
        string temp;
        stack<char> st;
        stack<int> num;
        while (i < n)
        {
            while (i < n && s[i] == ' ') i++;
            temp = "";
            while (i < n && s[i] >= '0' && s[i] <= '9') temp += s[i++];
            num.push(stoi(temp));

            while (i < n && s[i] == ' ') i++;
            if (i == n) break;

            if (st.empty() || priority(st.top()) < priority(s[i])) st.push(s[i++]);
            else
            {
                while (!st.empty() && priority(st.top())>=priority(s[i]))
                {
                    op1 = num.top();
                    num.pop();
                    op2 = num.top();
                    num.pop();
                    opr = st.top();
                    st.pop();
                    if (opr == '+') num.push(op2 + op1);
                    else if (opr == '-') num.push(op2 - op1);
                    else if (opr == '*') num.push(op2 *op1);
                    else num.push(op2 / op1);
                }
                st.push(s[i++]);
            }
        }
        while (!st.empty())
        {
            op1 = num.top();
            num.pop();
            op2 = num.top();
            num.pop();
            opr = st.top();
            st.pop();
            if (opr == '+') num.push(op2 + op1);
            else if (opr == '-') num.push(op2 - op1);
            else if (opr == '*') num.push(op2 *op1);
            else num.push(op2 / op1);
        }
        return num.top();
    }
};