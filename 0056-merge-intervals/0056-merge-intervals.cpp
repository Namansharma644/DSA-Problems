class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        
        for(auto &a : intervals)
        {
            if(res.empty() || res.back()[1]<a[0])
            {
                res.push_back(a);
            }
            else
            {
                res.back()[0]=min(res.back()[0],a[0]);
                res.back()[1]=max(res.back()[1],a[1]);
            }
        }
        return res;
    }
};