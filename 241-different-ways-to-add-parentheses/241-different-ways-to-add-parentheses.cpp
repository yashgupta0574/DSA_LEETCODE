class Solution
{
    public:
        int compute(int a, int b, char c)
        {
            if (c == '+') return a + b;
            else if (c == '-') return a - b;
            return a * b;
        }

    vector<int> diffWaysToCompute(string expression)
    {
        int n = expression.length();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> l = diffWaysToCompute(expression.substr(0, i));
                vector<int> r = diffWaysToCompute(expression.substr(i + 1));
                int n1 = l.size(), n2 = r.size();
                for (int j = 0; j < n1; j++)
                {
                    for (int k = 0; k < n2; k++)
                    {
                        ans.push_back(compute(l[j], r[k], expression[i]));
                    }
                }
            }
        }
        if (n <= 2) ans.push_back(stoi(expression));
        return ans;
    }
};