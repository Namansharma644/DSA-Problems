class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int freshOrange=0;


        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    freshOrange++;
                }
            }
        }

        if(freshOrange==0) return 0;
        int min=0;

        while(!q.empty())
        {
            int N=q.size();

            while(N--)
            {
                auto curr=q.front();
                q.pop();

                for(auto &dir : directions)
                {
                    int i=curr.first+dir[0];
                    int j=curr.second+dir[1];

                    if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
                    {
                        grid[i][j]=2;
                        q.push({i,j});
                        freshOrange--;
                    }
                }
            }
            min++;
        }

        return (freshOrange==0) ? (min-1) : -1;
    }
};