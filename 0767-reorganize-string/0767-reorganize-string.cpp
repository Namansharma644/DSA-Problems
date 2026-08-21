class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<int>map(26,0);

        int maxFreq=0;
        char maxFreqChar;

        for(char &c : s)
        {
            map[c-'a']++;

            if(map[c-'a']>maxFreq)
            {
                maxFreq=map[c-'a'];
                maxFreqChar=c;
            }

            if(map[c-'a']>(n+1)/2) return "";
        }

        string res=s;
        int i=0;

        while(map[maxFreqChar-'a']>0)
        {
            res[i]=maxFreqChar;
            i+=2;
            map[maxFreqChar-'a']--;
        }

        for(char ch='a'; ch<='z'; ch++)
        {
             while(map[ch-'a']>0)
             {
                if(i>=n)
                {
                    i=1;
                }

                res[i]=ch;
                i+=2;
                map[ch-'a']--;
             }
        }
        return res;
    }
};