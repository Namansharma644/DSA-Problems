class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;

        unordered_map<string , function<int(int,int)>>m={
              {"+",[](int a,int b){ return b+a;} },
              {"-",[](int a,int b){return b-a;} },
              {"/",[](int a,int b){return b/a;} },
              {"*",[](int a,int b){return (long long)b*(long long)a;}}
        };

        for(string &token : tokens)
        {
            if(token=="+" || token=="-" || token=="*" || token=="/")
            {
                 int a=s.top();
                 s.pop();

                 int b=s.top();
                 s.pop();

                 int res=m[token](a,b);
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