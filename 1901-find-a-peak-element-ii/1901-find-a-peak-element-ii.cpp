class Solution {
public:
    int findLargest(vector<vector<int>>& mat,int n,int m,int row)
    {
        int maxVal=INT_MIN;
        int index=-1;

        for(int i=0; i<m; i++)
        {
            if(maxVal<=mat[row][i])
            {
                maxVal=mat[row][i];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       vector<int>ans(2);
       int l=0,r=n-1;

       while(l<=r)
       {
        int mid=l+(r-l)/2;

        int col=findLargest(mat,n,m,mid);

        int top=mid-1>=0 ? mat[mid-1][col] : -1;
        int down=mid+1<n ? mat[mid+1][col] : -1;

            if(top<mat[mid][col] && down<mat[mid][col])
            {
                ans[0]=mid;
                ans[1]=col;
                return ans;
            }
            else if(top>mat[mid][col])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
       }
       return {-1,-1};
       }
};