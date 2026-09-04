class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;

        for(int &x : arr)
        {
            m[x]++;
        }

        unordered_set<int>s;

        for(auto &x : m)
        {
            s.insert(x.second);
        }

        return m.size()==s.size();
    }
};