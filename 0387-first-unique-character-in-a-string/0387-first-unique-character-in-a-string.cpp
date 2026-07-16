class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
    
        vector<int>map(26,0);

        for(char &c : s)
        {
            map[c-'a']++;
        }

        for(int i=0; i<n; i++)
        {
            if(map[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};