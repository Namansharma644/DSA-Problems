class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int a=-1;
        int b=-1;
        unordered_map<int,int>m;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                m[grid[i][j]]++;
            }
        }

        for(int i=1; i<=n*n; i++)
        {
            if(m.find(i)==m.end())
            {
                b=i;
            }
            else if(m[i]==2)
            {
                a=i;
            }
        }

        return {a,b};
    }
};