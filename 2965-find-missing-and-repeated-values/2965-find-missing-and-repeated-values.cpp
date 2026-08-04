class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long gridSum=0;
        long long gridSquareSum=0;
        long long N=n*n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                gridSum+=(long long)grid[i][j];
                gridSquareSum+=(long long)grid[i][j]*grid[i][j];
            }
        }

        long long sum=N*(N+1)/2;
        long long squareSum=N*(N+1)*(2*N+1)/6;

        long long sumDiff=gridSum-sum;
        long long squareDiff=gridSquareSum-squareSum;

        int  a=(sumDiff+squareDiff/sumDiff)/2;
        int  b=(squareDiff/sumDiff-sumDiff)/2;
        return {a,b};
    }
};