class Solution {
public:
    int operate(int a,int b,string &token)
    {
        if(token=="+")
        {
            return b+a;
        }
        if(token=="-")
        {
            return b-a;
        }
        if(token=="*")
        {
            return (long)b*(long)a;
        }
        if(token=="/")
        {
            return b/a;
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string &token : tokens)
        {
            if(token=="+" || token=="-" || token=="*" || token=="/")
            {
                 int a=s.top();
                 s.pop();

                 int b=s.top();
                 s.pop();

                 int res=operate(a,b,token);
                 s.push(res);
            }
            else
            {
                s.push(stoi(token));
            }
        }
       return s.top();
    }
};