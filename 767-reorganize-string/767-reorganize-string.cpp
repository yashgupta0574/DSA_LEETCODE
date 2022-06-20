class Solution
{
    public:
        static bool cc(string &a, string &b)
        {
            return a.length() > b.length();
        }
    string reorganizeString(string s)
    {
        int n = s.length(), j = 0;
        bool flag = true;
        sort(s.begin(), s.end());
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            j = i + 1;
            while (j < n && s[i] == s[j]) j++;
            v.push_back(s.substr(i, j - i));
            i = j - 1;
        }
        sort(v.begin(), v.end(), cc);
        s = "";
        j = v.size();
        for (int i = 0; i < j; i++) s += v[i];
       	//cout<<s<<endl;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1]) continue;
            j = i + 1;
            while (j + 1 < n && s[j] == s[j + 1]) j++;
            if (j + 1 < n) swap(s[i + 1], s[j + 1]);
            else
            {
                flag = false;
                break;
            }
        }
        if (flag) return s;
        else
        {
            reverse(s.begin(),s.end());
            flag=true;
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] != s[i + 1]) continue;
                j = i + 1;
                while (j + 1 < n && s[j] == s[j + 1]) j++;
                if (j + 1 < n) swap(s[i + 1], s[j + 1]);
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) return s;
        return "";
    }
};