class Solution
{
    public:
        string turnUp(string str, int i)
        {
            string ans = str;
            if (ans[i] == '9')
                ans[i] = '0';
            else
                ans[i] += 1;
            return ans;
        }
    string turnDown(string str, int i)
    {
        string ans = str;
        if (ans[i] == '0')
            ans[i] = '9';
        else
            ans[i] -= 1;
        return ans;
    }
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> visited;
        queue<string> q;

        for (string str: deadends)
            visited.insert(str);
        q.push("0000");
        int count = 0;
        while (q.empty() == false)
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return count;
                if (visited.find(curr) != visited.end())
                    continue;
                visited.insert(curr);
                for (int i = 0; i < 4; i++)
                {
                    string turnup = turnUp(curr, i);
                    string turndown = turnDown(curr, i);
                    if (visited.find(turnup) == visited.end())
                        q.push(turnup);
                    if (visited.find(turndown) == visited.end())
                        q.push(turndown);
                }
            }
            count++;
        }

        return -1;
    }
};