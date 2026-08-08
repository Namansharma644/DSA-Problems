class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>map(237,-1);
        int i=0,j=0;
        int maxLen=0;

        while(j<n)
        {
            if(map[s[j]]!=-1)
            {
                if(map[s[j]]>=i)
                {
                    i=map[s[j]]+1;
                }
            }

            maxLen=max(maxLen,j-i+1);
            map[s[j]]=j;
            j++;
        }
        return maxLen;
    }
};