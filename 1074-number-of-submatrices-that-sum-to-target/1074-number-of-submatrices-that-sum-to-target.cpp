class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        int res=0;
        for(int startCol=0; startCol<n; startCol++)
        {
            for(int j=startCol; j<n; j++)
            {
                unordered_map<int,int>map;
                map.insert({0,1});
                int cumSum=0;

                for(int row=0; row<m; row++)
                {
                     cumSum+=matrix[row][j]-((startCol!=0) ? matrix[row][startCol-1] : 0);

                     if(map.find(cumSum-target)!=map.end())
                     {
                        res+=map[cumSum-target];
                     }
                     map[cumSum]++;
                }
            }
        }
        return res;
    }
};