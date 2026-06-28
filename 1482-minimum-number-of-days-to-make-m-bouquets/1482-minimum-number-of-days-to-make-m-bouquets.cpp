class Solution {
public:
     int  possibleBouquets(vector<int>& bloomDay,int k,int mid)
     {
        int consequtive=0;
        int bouquets=0;

        for(int &d : bloomDay)
        {
            if(d<=mid)
            {
                consequtive++;
            }
            else
            {
                 consequtive=0;
            }

            if(consequtive==k)
            {
                bouquets++;
                consequtive=0;
            }
        }
        return  bouquets;
     }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());

        int res=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(possibleBouquets(bloomDay,k,mid)>=m)
            {
                res=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};