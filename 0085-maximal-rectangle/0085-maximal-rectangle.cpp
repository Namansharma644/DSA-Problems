class Solution {
public:
    int findMaxArea(vector<int>&heights)
    {
        int n=heights.size();
        stack<int>s;
        int maxArea=INT_MIN;

        for(int i=0; i<=n; i++)
        {
            int currEle=(i==n) ? 0 : heights[i];

            while(!s.empty() && heights[s.top()]>=currEle)
            {
                int idx=s.top();
                s.pop();
                int h=heights[idx];
                int prev=(s.empty()) ? -1 : s.top();
                int w=i-prev-1;
                maxArea=max(maxArea,h*w);
            }

            s.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;

        vector<int>heights(m);

        for(int i=0; i<m; i++)
        {
            heights[i]=(matrix[0][i]=='1') ? 1 : 0;
        }

        maxArea=findMaxArea(heights);

        for(int row=1; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(matrix[row][col]=='0')
                {
                    heights[col]=0;
                }
                else
                {
                    heights[col]+=1;
                }
            }

            maxArea=max(maxArea,findMaxArea(heights));
        }
        return maxArea;
    }
};