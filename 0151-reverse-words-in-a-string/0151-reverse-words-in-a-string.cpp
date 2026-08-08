class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);
        string token="";
        string res="";

        while(ss>>token)
        {
            res=token+" "+res;
        }

        return res.substr(0,res.length()-1);
    }
};