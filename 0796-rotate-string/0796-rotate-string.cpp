class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=goal.size();
        int n=s.size();
        if(m!=n) return false;

        for(int r=1; r<=n; r++)
        {
            bool ans=true;
            for(int j=0; j<n; j++)
            {
                if(s[(j+r)%n]!=goal[j])
                {
                    ans=false;
                    break;
                }
            }

            if(ans) return true;
        }
        return false;
    }
};