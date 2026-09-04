class Solution {
public:
    void dfs(vector<vector<char>>& board,int row,int col,vector<vector<int>>& vis,vector<vector<int>>&directions)
    {
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();

        for(auto &dir : directions)
        {
            int i=row+dir[0];
            int j=col+dir[1];

            if(i>=0 && i<n && j>=0 && j<m && board[i][j]=='O' && !vis[i][j])
            {
                dfs(board,i,j,vis,directions);
            }
        }


    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};

        for(int j=0; j<m; j++)
        {
            if(board[0][j]=='O' && !vis[0][j])
            {
                dfs(board,0,j,vis,directions);
            }

            if(board[n-1][j]=='O' && !vis[n-1][j])
            {
                dfs(board,n-1,j,vis,directions);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
            {
                dfs(board,i,0,vis,directions);
            }

            if(board[i][m-1]=='O' && !vis[i][m-1])
            {
                dfs(board,i,m-1,vis,directions);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};