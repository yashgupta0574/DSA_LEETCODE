class Solution {
public:
    int calculate(string s) {
          stack<int> st;
        
        int sum = 0;
        int sign = 1;                        // +1 = Positive sign and -1 = Negative sign
        
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            
            if(ch == '-')
            {
                sign = -1;
            }
            else if(isdigit(ch))
            {   
                int val = 0;
                
                while(i<s.size() && isdigit(s[i]))       //calculating value if it has two or more digit
                {
                    val = val*10 + (s[i++]-'0');
                }
                i--;
                
                val = val*sign;        //multiply value with sign just before it
                sum = sum + val;      //add value to the sum
                sign = 1;            //reset sign
            }
            else if(ch == '(')
            {
                st.push(sum);        //push sum outside bracket onto stack
                st.push(sign);      //after sum push sign just outside the bracket onto stack
                sum = 0;           //reset sum and sign
                sign = 1;
            }
            else if(ch == ')')
            {
                sum *= st.top();    //multiply sum that is within bracket with sign just outside bracket
                st.pop();
                sum += st.top();    //sum outside the bracket + sum inside the bracket
                st.pop();
            }
        }
        
        return sum;
    }
};