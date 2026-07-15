class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;
        int n=senate.size();

        for(int i=0; i<n; i++)
        {
            (senate[i]=='R') ? r.push(i) : d.push(i);
        }

        while(r.size()>0  && d.size()>0)
        {
            int rId=r.front();
            r.pop();
            int dId=d.front();
            d.pop();

            (rId<dId) ? r.push(rId+n) : d.push(dId+n);
        }

        return (r.size()==0) ? "Dire" : "Radiant";
    }
};