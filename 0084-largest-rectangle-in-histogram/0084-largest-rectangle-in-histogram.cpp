class Solution {
public:
    vector<int>  findRightSmaller(vector<int>&heights,int n)
    {
       vector<int>ans(n);
       stack<int>s;

       for(int i=n-1; i>=0; i--)
       {
           while(!s.empty() && heights[s.top()]>=heights[i])
           {
             s.pop();
           }

           ans[i]=s.empty() ? n : s.top();

           s.push(i);
       }
      return ans;
    }
    vector<int>  findLeftSmaller(vector<int>&heights,int n)
    {
       vector<int>ans(n);
       stack<int>s;

       for(int i=0; i<n; i++)
       {
           while(!s.empty() && heights[s.top()]>=heights[i])
           {
             s.pop();
           }

           ans[i]=s.empty() ? -1 : s.top();

           s.push(i);
       }
      return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left=findLeftSmaller(heights,n);
        vector<int>right=findRightSmaller(heights,n);
        int ans=INT_MIN;

         for(int i=0; i<n; i++)
         {
            int h=heights[i];
            int w=right[i]-left[i]-1;
            ans=max(ans,h*w);
         }
         return ans;
    }
};