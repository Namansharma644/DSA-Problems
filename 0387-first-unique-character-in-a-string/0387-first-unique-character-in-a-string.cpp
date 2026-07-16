class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        queue<int>q;
        vector<int>map(26,0);

        for(int i=0; i<n; i++)
        {
            map[s[i]-'a']++;
            q.push(i);
        }

        while(!q.empty())
        {
            int idx=q.front();
            q.pop();

            if(map[s[idx]-'a']==1)
            {
                return idx;
            }
        }
        return -1;
    }
};