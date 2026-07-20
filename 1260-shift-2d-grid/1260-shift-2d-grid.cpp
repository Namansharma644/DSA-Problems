class Solution {
public:
    void rotate(vector<vector<int>>& grid,int n,int m)
    {
        int temp=grid[n-1][m-1];

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i!=0 || j!=0)
                {
                    if(j>0)
                    {
                        grid[i][j]=grid[i][j-1];
                    }
                    else
                    {
                        grid[i][j]=grid[i-1][m-1];
                    }
                }
            }
        }
            grid[0][0]=temp;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<k; i++)
        {
            rotate(grid,n,m);
        }
        return grid;
    }
};