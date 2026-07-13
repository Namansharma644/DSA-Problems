class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int>s;
        s.push(0);

        for(char c : str)
        {
            if(c=='(')
            {
                s.push(0);
            }
            else
            {
                int val=s.top();
                s.pop();
                int score=max(2*val,1);
                int prevScore=s.top();
                s.pop();
                s.push(score+prevScore);
            }
        }
        return s.top();
    }
};