class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int count=0;
        int last=INT_MIN;

        for(auto &a : intervals)
        {
            if(last<=a[0])
            {
                count++;
                last=a[1];
            }
        }

        return intervals.size()-count;
    }
};