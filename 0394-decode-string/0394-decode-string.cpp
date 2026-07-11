class Solution {
public:
    string decodeString(string str) {
        stack<string>s;
        stack<int>num;
        int n=str.size();

        for(int i=0; i<n; i++)
        {
            if(isdigit(str[i]))
            {
                int number = 0;

                while (i < str.size() && isdigit(str[i]))
                {
                    number = number * 10 + (str[i] - '0');
                    i++;
                }

                num.push(number);
                i--;   
            }
            else if( (str[i]>='a' && str[i]<='z') || str[i]=='[')
            {
                s.push(string(1,str[i]));
            }
            else 
            {
                string temp="";
                while(!s.empty() && s.top()!="[")
                {
                    temp=s.top()+temp;
                    s.pop();
                }
                s.pop();

                int digit=num.top();
                num.pop();

                string res="";
                for(int i=0; i<digit; i++)
                {
                    res+=temp;
                }
                s.push(res);
            }
        }

        string ans="";
        while(!s.empty())
        {
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
    }
};