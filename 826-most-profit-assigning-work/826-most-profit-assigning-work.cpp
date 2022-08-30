class Solution
{
    public:
    static bool cc(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.first>p2.first;
    }
        int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector< int > &worker)
        {
            vector<pair<int, int>> v;
            int n = worker.size(),m=worker.size();
            for (int i = 0; i < n; i++)
            {
                v.push_back({ profit[i],
                    difficulty[i] });
            }
            sort(v.begin(), v.end(),cc);
            sort(worker.begin(),worker.end(),greater<int>());
            int i=0,ans=0,cnt=0;
            while(i<n)
            {
                while(cnt<m && v[i].second<=worker[cnt])
                {
                    ans+=v[i].first;
                    cnt++;
                    cout<<ans<<" ";
                }
                i++;
            }
            return ans;
        }
};