class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>temp(m,vector<int>(n,0));
        int col=n-1;

        for(int i=0; i<m; i++)
        {
            int k=0;
            for(int j=0; j<n; j++)
            {
                temp[k][col]=matrix[i][j];
                k++;
            }
            col--;
        }
        matrix=temp;
    }
};