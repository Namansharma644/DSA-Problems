class Solution {
public:
    string makeGood(string str){
        stack<char>s;
        
        for(char &c : str)
        {
            if(!s.empty() && abs(s.top()-c)==32)
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