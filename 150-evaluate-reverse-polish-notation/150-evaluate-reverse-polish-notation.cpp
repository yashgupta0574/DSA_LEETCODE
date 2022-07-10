class Solution
{
    public:
        int evalRPN(vector<string> &tokens)
        {
            int n = tokens.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") st.push(stoi(tokens[i]));
                else
                {
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.pop();
                    if (tokens[i] == "+") st.push(top2 + top1);
                    else if (tokens[i] == "-") st.push(top2 - top1);
                    else if (tokens[i] == "*") st.push(top2 *top1);
                    else st.push(top2 / top1);
                }
            }
            return st.top();
        }
};