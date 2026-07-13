class Solution {
public:
    string removeDuplicates(string str) {
       string res="";

        for(char &c : str)
        {
            if(!res.empty() && res.back()==c)
            {
                res.pop_back();
            }
            else
            {
                res.push_back(c);
            }
        }
            return res;
        }
};