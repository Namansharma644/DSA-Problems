class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=0;
        int len=0;
        int ans=0;

        while(i<n)
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }
            len++;
            if(i+1>=n || s[i+1]==' ')
            {
                ans=len;
                len=0;
            }
            i++;
        }
        return ans;
    }
};