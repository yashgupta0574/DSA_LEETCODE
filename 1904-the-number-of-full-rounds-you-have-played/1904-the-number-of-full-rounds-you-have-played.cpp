class Solution
{
    public:
        int numberOfRounds(string loginTime, string logoutTime)
        {
            int stl, enl, stg, eng, ans = 0;
            stl = (loginTime[0] - '0') *10 + loginTime[1] - '0';
            enl = (logoutTime[0] - '0') *10 + logoutTime[1] - '0';
            stg = (loginTime[3] - '0') *10 + loginTime[4] - '0';
            eng = (logoutTime[3] - '0') *10 + logoutTime[4] - '0';
            if (stl == enl && stg <= eng)
            {
                if (eng % 15 != 0) eng -= (eng % 15);
                if (stg % 15 != 0) stg += (15 - stg % 15);
                return (enl - stl) *4 - (stg / 15) + (eng / 15)<0?0:(enl - stl) *4 - (stg / 15) + (eng / 15);
            }
            if (stg % 15 != 0)
            {
                if (stg > 45)
                {
                    stg = 0;
                    stl++;
                }
                else stg += (15 - stg % 15);
            }
            if (eng % 15 != 0) eng -= (eng % 15);
            if (stl <= enl)
            {
                if (stl == enl)
                {
                    if (stg <= eng) return (enl - stl) *4 - (stg / 15) + (eng / 15);
                    else return (24 - stl) *4 - stg / 15 + enl *4 + eng / 15;
                }
                return (enl - stl) *4 - (stg / 15) + (eng / 15);
            }
            return (24 - stl) *4 - stg / 15 + enl *4 + eng / 15;
        }
};