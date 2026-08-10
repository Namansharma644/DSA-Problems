class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=goal.size();
        int n=s.size();
        if(m!=n) return false;

        for(int r=1; r<=n; r++)
        {
            string temp=s;
           reverse(temp.begin(), temp.begin() + r);
           reverse(temp.begin() + r, temp.end());
            reverse(temp.begin(), temp.end());
            if(temp==goal) return true;
        }
        return false;
    }
};