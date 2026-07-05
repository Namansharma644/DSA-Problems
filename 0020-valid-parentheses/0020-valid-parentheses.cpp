class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(char &s :  str)
        {
            if(s=='(' || s=='{' || s=='[')
            {
                st.push(s);
            }
            else
            {
                if(st.size()==0)
                {
                    return false;
                }
                if(s==')' && st.top()=='(' || s=='}' && st.top()=='{' || s==']' && st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.size()==0;
    }
};