class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=goal.size();
        int n=s.size();
        if(m!=n) return false;

        string temp=s+s;

        return temp.find(goal)!=string::npos;
    }
};