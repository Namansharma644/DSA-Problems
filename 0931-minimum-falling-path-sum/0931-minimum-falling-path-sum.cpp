class Solution {
public:
    int helper(int r,int c,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(c<0 || c>=n) return 1e9;
        if(r==0) return matrix[0][c];

        if(dp[r][c]!=INT_MAX) return dp[r][c];

        int up=matrix[r][c]+helper(r-1,c,n,matrix,dp);
        int digonalLeft=matrix[r][c]+helper(r-1,c-1,n,matrix,dp);
        int diagonalRight=matrix[r][c]+helper(r-1,c+1,n,matrix,dp);

        return dp[r][c]=min(up,min(digonalLeft,diagonalRight)); 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int mini=INT_MAX;

        for(int j=0; j<n; j++)
        {
            mini=min(mini,helper(n-1,j,n,matrix,dp));
        }
        return mini;
    }
};