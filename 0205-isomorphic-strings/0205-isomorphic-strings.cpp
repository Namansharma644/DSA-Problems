class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        int m1[256] = {0};
        int m2[256] = {0};

        for(int i = 0; i < s.size(); i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];

            if((m1[ch1] != 0 && m1[ch1] != ch2) ||
               (m2[ch2] != 0 && m2[ch2] != ch1))
            {
                return false;
            }

            m1[ch1] = ch2;
            m2[ch2] = ch1;
        }
        
        return true;
    }
};