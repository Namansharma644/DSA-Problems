class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<int>>&directions)
    {
        grid[row][col]='$';
        int n=grid.size();
        int m=grid[0].size();

        for(auto &dir : directions)
        {
            int i=row+dir[0];
            int j=col+dir[1];

            if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
            {
                dfs(grid,i,j,directions);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        int count=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j,directions);
                }
            }
        }
        return count;
    }
};