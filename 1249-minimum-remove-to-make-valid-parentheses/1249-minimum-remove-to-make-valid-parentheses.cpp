class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        unordered_set<int>ignore;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    ignore.insert(i);
                }
                else
                {
                    st.pop();
                }
            }
        }

        while(!st.empty())
        {
            ignore.insert(st.top());
            st.pop();
        }

        string res="";

        for(int i=0; i<n; i++)
        {
            if(ignore.find(i)==ignore.end())
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};