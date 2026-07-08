class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string res="";

        for(char &a : num)
        {
            while(!res.empty() && res.back()>a && k>0)
            {
                res.pop_back();
                k--;
            }

            if(!res.empty() || a!='0')
            {
                res.push_back(a);
            }
        }

        while(!res.empty() && k>0)
        {
            res.pop_back();
            k--;
        }
        
        if(res=="")
        {
            return "0";
        }
        return res;
    }
};