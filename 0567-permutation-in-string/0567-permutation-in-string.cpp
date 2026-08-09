class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();

        if(m>n) return false;
        int i=0,j=0;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(char &c : s1)
        {
            freq1[c-'a']++;
        }

        while(j<n)
        {
            freq2[s2[j]-'a']++;
            while(j-i+1>m)
            {
                freq2[s2[i]-'a']--;
                i++;
            }

            if(freq1==freq2) return true;
            j++;
        }

        return false;
    }
};