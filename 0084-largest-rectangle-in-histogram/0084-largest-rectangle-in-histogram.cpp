class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int ans=INT_MIN;

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
                ans=max(ans,h*w);
            }

            s.push(i);
        }
        return ans;
    }
};