class Solution {
public:
    bool isPossible(vector<int>& position, int mid,int m)
    {
        int ballsCount=1;
        int last=position[0];

        for(int i=1; i<position.size(); i++)
        {
            if(position[i]-last>=mid)
            {
                ballsCount++;
                last=position[i];
            }

            if(ballsCount==m)
            {
                break;
            }
        }

        return ballsCount==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());

        int l=1;
        int r=position[n-1]-position[0];
        int ans=-1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(isPossible(position,mid,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }

        }
        return ans;  
    }
};