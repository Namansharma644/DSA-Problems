class Solution {
public:
    void constructLSP(vector<int>&LSP,string &needle)
    {
        int i=1;
        int length=0;
        LSP[0]=0;

        while(i<needle.size())
        {
            if(needle[i]==needle[length])
            {
                length++;
                LSP[i]=length;
                i++;
            }
            else
            {
                if(length!=0)
                {
                   length=LSP[length-1];
                }
                else
                {
                    length=0;
                    LSP[i]=0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        if(m>n) return -1;

        vector<int>LSP(m,0);
        constructLSP(LSP,needle);

        int i=0;
        int j=0;

        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }

            if(j==m)
            {
                return i-j;
            }
            else if(haystack[i]!=needle[j])
            {
                if(j!=0)
                {
                    j=LSP[j-1];
                }
                else
                {
                    i++;
                }
            }
        }

        return -1;
    }
};