class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();

        if(m>n) return false;

        vector<int>freq1(26,0);
        

        for(char &c : s1)
        {
            freq1[c-'a']++;
        }

        for(int i=0; i<=n-m; i++)
        {
            vector<int>freq2(26,0);
            for(int j=i; j<i+m; j++)
            {
                freq2[s2[j]-'a']++;
            }

            bool isSame=true;
            for(int i=0; i<26; i++)
            {
                if(freq1[i]!=freq2[i])
                {
                    isSame=false;
                    break;
                }
            }

            if(isSame) return true;
        }
        return false;
    }
};