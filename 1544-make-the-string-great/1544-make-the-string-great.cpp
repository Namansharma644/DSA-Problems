class Solution {
public:
    string makeGood(string str){
        string res="";
        
        for(char &c : str)
        {
            if(!res.empty() && abs(res.back()-c)==32)
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