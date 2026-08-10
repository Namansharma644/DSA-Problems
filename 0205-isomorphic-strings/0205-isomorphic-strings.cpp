class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;

        for(int i=0; i<n; i++)
        {
            char ch1=s[i];
            char ch2=t[i];

            if(m1.find(ch1)!=m1.end() && m1[ch1]!=ch2 || m2.find(ch2)!=m2.end() && m2[ch2]!=ch1)
            {
                return false;
            }

            m1[ch1]=ch2;
            m2[ch2]=ch1;
        }
        return true;
    }
};