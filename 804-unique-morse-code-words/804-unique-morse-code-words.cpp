class Solution
{
    public:
        int uniqueMorseRepresentations(vector<string> &words)
        {
            vector<string> c = { ".-",
                "-...",
                "-.-.",
                "-..",
                ".",
                "..-.",
                "--.",
                "....",
                "..",
                ".---",
                "-.-",
                ".-..",
                "--",
                "-.",
                "---",
                ".--.",
                "--.-",
                ".-.",
                "...",
                "-",
                "..-",
                "...-",
                ".--",
                "-..-",
                "-.--",
                "--.." };
            unordered_map<string, bool> mp;
            int n = words.size();
            for (int i = 0; i < n; i++)
            {
                string s;
                for (int j = 0; j < words[i].length(); j++) s += c[words[i][j] - 'a'];
                mp[s] = true;
            }
            return mp.size();
        }
};