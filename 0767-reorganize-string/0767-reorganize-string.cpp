class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<int>map(26,0);

        for(char &c : s)
        {
            map[c-'a']++;

            if(map[c-'a']>(n+1)/2) return "";
        }

        priority_queue<pair<int,char>>pq;

        for(char ch='a'; ch<='z'; ch++)
        {
            if(map[ch-'a']>0)
            {
                pq.push({map[ch-'a'],ch});
            }
        }
        
        string res="";
        while(pq.size()>=2)
        {
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();

            res.push_back(p1.second);
            p1.first--;

            res.push_back(p2.second);
            p2.first--;

            if(p1.first>0)
            {
                pq.push(p1);
            }

            if(p2.first>0)
            {
                pq.push(p2);
            }
        }

        if(!pq.empty())
        {
            res.push_back(pq.top().second);
        }
        return res;
    }
};