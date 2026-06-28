class Solution {
public:
     bool isPossible(vector<int>& piles, int h,int mid)
     {
        long long hours=0;

        for(int &a : piles)
        {
            hours+=a/mid;

            if(a%mid !=0)
            {
                hours++;
            }
        }

        return hours<=h;
     }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());

        while(l<r)
        {
            int mid=l+(r-l)/2;

            if(isPossible(piles,h,mid))
            {
                r=mid;
            
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};