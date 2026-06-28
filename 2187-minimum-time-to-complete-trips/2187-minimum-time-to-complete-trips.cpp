class Solution {
public:
    bool isPossible(vector<int>& time, int totalTrips,long long mid)
    {
        long long trips=0;

        for(int &a : time)
        {
            trips+=mid/a;
        }

        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
       long long l=0;
       long long r = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
       while(l<r)
       {
          long long mid=l+(r-l)/2;

          if(isPossible(time,totalTrips,mid))
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