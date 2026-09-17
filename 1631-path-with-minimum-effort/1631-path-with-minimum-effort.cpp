class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==m-1) return diff;

            vector<vector<int>>distances={{0,1},{1,0},{-1,0},{0,-1}};
            for(auto &it : distances)
            {
                int i=row+it[0];
                int j=col+it[1];

                if(i>=0 && i<n && j>=0 && j<m)
                {
                    int newDiff=max(abs(heights[row][col]-heights[i][j]),diff);
                    if(newDiff<dis[i][j])
                    {
                        dis[i][j]=newDiff;
                        pq.push({newDiff,{i,j}});
                    }
                }      
            }
        }
        return 0;
    }
};