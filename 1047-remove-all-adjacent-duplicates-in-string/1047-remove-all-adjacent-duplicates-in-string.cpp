class Solution {
public:
    string removeDuplicates(string str) {
        stack<char>s;

        for(char &c : str)
        {
            if(!s.empty() && s.top()==c)
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }

            string res="";
            while(!s.empty())
            {
                res=s.top()+res;
                s.pop();
            }
            return res;
        }
};