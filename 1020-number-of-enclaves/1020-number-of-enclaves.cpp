class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&vis,vector<vector<int>>&directions)
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();


        for(auto &dir : directions)
        {
            int i=row+dir[0];
            int j=col+dir[1];

            if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1 && !vis[i][j])
            {
                dfs(grid,i,j,vis,directions);  
            }
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};

        for(int j=0; j<m; j++)
        {
            if(grid[0][j]==1 && !vis[0][j])
            {
                dfs(grid,0,j,vis,directions);
            }

            if(grid[n-1][j]==1 && !vis[n-1][j])
            {
                dfs(grid,n-1,j,vis,directions);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==1 && !vis[i][0])
            {
                dfs(grid,i,0,vis,directions);
            }

            if(grid[i][m-1]==1 && !vis[i][m-1])
            {
                dfs(grid,i,m-1,vis,directions);
            }
        }

        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
               if(grid[i][j]==1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
};