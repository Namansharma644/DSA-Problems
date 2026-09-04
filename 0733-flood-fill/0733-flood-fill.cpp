class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,vector<vector<int>>&directions,int intialColor)
    {
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();

        for(auto &dir : directions)
        {
            int i=sr+dir[0];
            int j=sc+dir[1];

            if(i>=0 && i<n && j>=0 && j<m && image[i][j]==intialColor)
            {
                dfs(image,i,j,color,directions,intialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      

        int intialColor=image[sr][sc];
        if(intialColor==color) return image;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        dfs(image,sr,sc,color,directions,intialColor);

        return image;
    }
};