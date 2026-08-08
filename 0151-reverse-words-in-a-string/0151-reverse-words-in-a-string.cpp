class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int idx=0;
        string res="";

        while(idx<n)
        {
             string word="";
            while(idx<n && s[idx]!=' ')
            {
                word+=s[idx++];
            }

            if(!word.empty())  res=word+" "+res;

            while(idx<n && s[idx]==' ') idx++;
        }

        if(!res.empty()) res.pop_back();
        return res;
    }
};