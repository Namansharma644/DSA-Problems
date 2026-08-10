class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>map;

        for(char &c : s)
        {
            map[c]++;
        }

        vector<pair<char,int>>arr;
        for(auto &it : map)
        {
           pair<char,int>p={it.first,it.second};
           arr.push_back(p);
        }

        sort(arr.begin(),arr.end(),[&](auto &p1,auto &p2){
            return p1.second>p2.second;
        });

        string res="";
        for(int i=0; i<arr.size(); i++)
        {
            int freq=arr[i].second;
            char ch=arr[i].first;
            string temp=string(freq,ch);
            res+=temp;
        }
        return res;
    }
};