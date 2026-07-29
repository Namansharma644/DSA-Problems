class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxArea=0;

        int i=0,j=n-1;

        while(i<j)
        {
            int h=min(height[i],height[j]);
            int w=j-i;
            maxArea=max(maxArea,h*w);

            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return maxArea;
    }
};