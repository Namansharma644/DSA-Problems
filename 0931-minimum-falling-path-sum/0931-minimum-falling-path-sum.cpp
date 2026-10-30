class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int j=0; j<n; j++)
        {
            dp[0][j]=matrix[0][j];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int st=matrix[i][j]+dp[i-1][j];
                int diagonalLeft=1e9;
                int diagonalRight=1e9;

                if(j>0) diagonalLeft=matrix[i][j]+dp[i-1][j-1];
                if(j<n-1) diagonalRight=matrix[i][j]+dp[i-1][j+1];

                dp[i][j]=min(st,min(diagonalLeft,diagonalRight));
            }
        }
         
        int mini=INT_MAX;
        for(int j=0; j<n; j++)
        {
             mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};