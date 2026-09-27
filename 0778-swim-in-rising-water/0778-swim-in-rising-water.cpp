class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int n;
    bool possibleReach(vector<vector<int>>&grid,int i,int j,int t,vector<vector<int>>&visited)
    {
        if(i<0 || i>=n || j<0 || j>=n || visited[i][j] || grid[i][j]>t)
        {
            return false;
        }

        visited[i][j]=true;

        if(i==n-1 && j==n-1) return true;

        for(auto &dir : directions)
        {
            int row=i+dir[0];
            int col=j+dir[1];

            if(possibleReach(grid,row,col,t,visited))
            {
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();

        int l=grid[0][0];
        int r=n*n-1;
        int ans=-1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            vector<vector<int>>visited(n,vector<int>(n,false));
            if(possibleReach(grid,0,0,mid,visited))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    return ans;
    }
};