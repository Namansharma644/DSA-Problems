class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int end=-1;

        for(int i=n-1; i>=0; i--)
        {
            if((num[i]-'0')%2 != 0)
            {
                end=i;
                break;
            }
        }
        return (end==-1) ? "" : num.substr(0,end+1);
    }
};