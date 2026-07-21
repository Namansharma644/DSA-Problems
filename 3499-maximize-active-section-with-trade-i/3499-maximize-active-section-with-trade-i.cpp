class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>inactiveSection;
        int countOne=count(s.begin(),s.end(),'1');
        int i=0;
        int n=s.size();

        while(i<n)
        {
            if(s[i]=='0')
            {
                int start=i;
                while(i<n && s[i]=='0') i++;
                inactiveSection.push_back(i-start);
            }
            else
            {
                i++;
            }
        }

        int maxSum=0;
        for(int i=1; i<inactiveSection.size(); i++)
        {
            maxSum=max(maxSum, inactiveSection[i]+inactiveSection[i-1]);
        }
        return maxSum+countOne;
    }
};