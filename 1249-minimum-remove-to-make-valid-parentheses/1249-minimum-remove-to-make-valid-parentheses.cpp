class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string temp="";

        int open=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                open++;
                temp.push_back(s[i]);
            }
            else if(s[i]==')')
            {
                if(open>0)
                {
                    temp.push_back(s[i]);
                    open--;
                }
            }
            else
            {
              temp.push_back(s[i]);
            }
        }

        int close=0;
        string res="";
        for(int i=temp.size()-1; i>=0; i--)
        {
            if(temp[i]==')')
            {
                close++;
                res.push_back(temp[i]);
            }
            else if(temp[i]=='(')
            {
                if(close>0)
                {
                    res.push_back(temp[i]);
                    close--;
                }
            }
            else
            {
              res.push_back(temp[i]);
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};