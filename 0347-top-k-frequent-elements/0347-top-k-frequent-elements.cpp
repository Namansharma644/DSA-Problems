class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;

        for(int &a : nums)
        {
            m[a]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto &it : m)
        {
            pq.push({it.second,it.first});

            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<int>res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};