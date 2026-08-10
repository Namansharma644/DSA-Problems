class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int maxDepth=0;
        int depth=0;

        for(char &c : s)
        {
            if(c=='(')
            {
                depth++;
                maxDepth=max(maxDepth,depth);
            }
            else if(c==')')
            {
                depth--;
            }
        }

        return maxDepth;
    }
};