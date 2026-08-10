class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        vector<pair<char,int>>map(123);

        for(char &c : s)
        {
            int freq=map[c].second;
            map[c]={c,freq+1};
        }

        sort(map.begin(),map.end(),[&](auto &p1,auto &p2){
            return p1.second>p2.second;
        });

        string res="";
        for(int i=0; i<123; i++)
        {
            if(map[i].second>0)
            {
                char ch=map[i].first;
                int freq=map[i].second;
                string temp=string(freq,ch);
                res+=temp;
            }
        }
        return res;
    }
};