class Solution {
public:
    int requiredDays(vector<int>& weights, int mid)
    {
          int days=1,load=0;

          for(int &a : weights)
          {
            if(load+a>mid)
            {
                days++;
                load=a;
            }
            else
            {
                load+=a;
            }
          }
          return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(requiredDays(weights,mid)<=days)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    return ans; 
    }
};