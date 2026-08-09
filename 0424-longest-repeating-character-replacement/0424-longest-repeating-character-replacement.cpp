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
            if(((j-i+1)-maxFreq)>k)
            {
                map[s[i]-'A']--;
                i++;
            }

            maxLen=max(maxLen,j-i+1);
            j++;
        }

        return maxLen;
    }
};