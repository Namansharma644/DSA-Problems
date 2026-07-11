class Solution {
public:
    int calculate(string str) {
        stack<long long>s;
        long long res=0;
        long long sign=1;
        long long num=0;

        for(char &c : str)
        {
            if(isdigit(c))
            {
                num=(long long)num*10+(c-'0');
            }
            else if(c=='+')
            {
                res+=(num*sign);
                num=0;
                sign=1;
            }
            else if(c=='-')
            {
                res+=(num*sign);
                num=0;
                sign=-1;
            }
            else if(c=='(')
            {
                s.push(res);
                s.push(sign);

                num=0;
                res=0;
                sign=1;
            }
            else if(c==')')
            {
                res+=(num*sign);
                num=0;

                int prevSign=s.top();
                s.pop();

                int prevRes=s.top();
                s.pop();

                res*=prevSign;
                res+=prevRes;
            }
        }

        res+=(num*sign);
        return (int)res;
    }
};