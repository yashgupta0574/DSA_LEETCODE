class Solution
{
    public:
        int mod = 1e9 + 7;
    unordered_map<char, vector < char>> mp;
    vector<vector < int>> dp;
    int n;

    long long int solve(int idx, char ch)
    {
        if (idx == n-1) return 1;
        if (dp[idx][ch - 'a'] != -1) return dp[idx][ch - 'a'];
        long long int total = 0;
        for(auto it:mp[ch]) total += (solve(idx + 1, it) % mod);
        return dp[idx][ch-'a'] = (total % mod);
    }

    int countVowelPermutation(int N)
    {
        mp['a'].push_back('e');
        mp['e'].push_back('a');
        mp['e'].push_back('i');
        mp['i'].push_back('a');
        mp['i'].push_back('e');
        mp['i'].push_back('o');
        mp['i'].push_back('u');
        mp['o'].push_back('i');
        mp['o'].push_back('u');
        mp['u'].push_back('a');
        n = N;
        dp = vector<vector < int>> (n + 1,vector<int>(27,-1));
        long long int ans = solve(0, 'a') % mod;
        ans += (solve(0, 'e') % mod);
        ans += (solve(0, 'i') % mod);
        ans += (solve(0, 'o') % mod);
        ans += (solve(0, 'u') % mod);
        return ans%mod;
    }
};