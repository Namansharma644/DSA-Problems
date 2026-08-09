class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        int maxFreq=0;
        int i=0,j=0;
        vector<int>map(26,0);

        while(j<n)
        {
            map[s[j]-'A']++;
            maxFreq=max(maxFreq,map[s[j]-'A']);
            while(((j-i+1)-maxFreq)>k)
            {
                map[s[i]-'A']--;
                for(int i=0; i<26; i++)
                {
                    maxFreq=max(maxFreq,map[i]);
                }
                i++;
            }

            if((j-i+1)-maxFreq<=k)
            {
                maxLen=max(maxLen,j-i+1);
            }
            j++;
        }

        return maxLen;
    }
};