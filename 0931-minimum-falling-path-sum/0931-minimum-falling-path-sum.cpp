class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>prev(n,0);

        for(int j=0; j<n; j++)
        {
            prev[j]=matrix[0][j];
        }

        for(int i=1; i<n; i++)
        {
            vector<int>curr(n,0);

            for(int j=0; j<n; j++)
            {
                int st=matrix[i][j]+prev[j];
                int diagonalLeft=1e9;
                int diagonalRight=1e9;

                if(j>0) diagonalLeft=matrix[i][j]+prev[j-1];
                if(j<n-1) diagonalRight=matrix[i][j]+prev[j+1];

                curr[j]=min(st,min(diagonalLeft,diagonalRight));
            }
            prev=curr;
        }
         
        int mini=INT_MAX;
        for(int j=0; j<n; j++)
        {
             mini=min(mini,prev[j]);
        }
        return mini;
    }
};