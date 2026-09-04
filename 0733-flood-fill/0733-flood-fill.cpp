class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int intialColor=image[sr][sc];
        if(intialColor==color) return image;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int i=r+dir[0];
                int j=c+dir[1];

                if(i>=0 && i<n && j>=0 && j<m && image[i][j]==intialColor)
                {
                    image[i][j]=color;
                    q.push({i,j});
                }
            }
        } 
        return image;
    }
};