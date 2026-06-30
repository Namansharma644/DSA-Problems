class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int count=INT_MIN;
        vector<int>ans(2);

        for(int i=0; i<m; i++)
        {
            int countRow=0;
            for(int j=0; j<n; j++)
            {
               if(mat[i][j]==1)
               {
                 countRow++;
               }
            }

            if(countRow>count)
            {
                count=countRow;
                ans[0]=i;
                ans[1]=count;
            }
        }
       return ans; 
    }
};