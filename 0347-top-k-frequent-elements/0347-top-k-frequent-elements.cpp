class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;

        for(int &a : nums)
        {
            m[a]++;
        }

        vector<pair<int,int>>vec;

        for(auto &it : m)
        {
            vec.push_back({it.second,it.first});
        }

        sort(vec.begin(),vec.end(),greater<pair<int,int>>());

        vector<int>res;
        for(int i=0; i<k; i++)
        {
            res.push_back(vec[i].second);
        }
        return res;
    }
};