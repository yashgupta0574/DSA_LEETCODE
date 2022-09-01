class Solution
{
    public:
        vector<string> invalidTransactions(vector<string> &transactions)
        {
            vector<string> ans;
            int l = transactions.size(), sz, j;
            vector<string> name;
            vector<int> time;
            vector<int> amount;
            vector<string> city;
            string n, t, a, c;
            for (int i = 0; i < l; i++)
            {
                sz = transactions[i].size(), j = 0;
                n = "";
                t = "";
                a = "";
                c = "";
                while (transactions[i][j] != ',')
                {
                    n += transactions[i][j++];
                }
               	//cout<<n<<endl;
                name.push_back(n);
                j++;
                while (transactions[i][j] != ',')
                {
                    t += transactions[i][j++];
                }
               	//cout<<t<<endl;
                time.push_back(stoi(t));
                j++;
                while (transactions[i][j] != ',')
                {
                    a += transactions[i][j++];
                }
               	//cout<<a<<endl;
                amount.push_back(stoi(a));
                j++;
                while (j != sz)
                {
                    c += transactions[i][j++];
                }
               	//cout<<c<<endl;
                city.push_back(c);
            }
            unordered_set<int> s;
            for (int i = 0; i < l; i++)
            {
                for (int j = i; j < l; j++)
                {
                    if (abs(time[j] - time[i]) <= 60 && city[i] != city[j] && name[i] == name[j])
                    {
                        if (s.find(i) == s.end())
                        {
                            ans.push_back(transactions[i]);
                            s.insert(i);
                        }
                        if (s.find(j) == s.end())
                        {
                            ans.push_back(transactions[j]);
                            s.insert(j);
                        }
                    }
                }
            }
            for (int j = 0; j < l; j++)
            {
                if (amount[j] > 1000 && s.find(j) == s.end())
                {
                    ans.push_back(transactions[j]);
                    s.insert(j);
                }
            }
            return ans;
        }
};