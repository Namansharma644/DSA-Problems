class Solution {
public:
    int helper(int r,int c,int m,int n,vector<vector<int>>&dp)
    {
        if(r==m-1 && c==n-1) return 1;
        if(r<0 || r>=m || c<0 || c>=n) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        int rs=helper(r,c+1,m,n,dp);
        int ls=helper(r+1,c,m,n,dp);

        return dp[r][c]=rs+ls;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
    }
};