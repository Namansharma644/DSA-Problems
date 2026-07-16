class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t=0;
        int n=tickets.size();
        queue<int>q;

        for(int i=0; i<n; i++)
        {
            q.push(i);
        }

        while(!q.empty() && tickets[k]>0)
        {
            int idx=q.front();
            q.pop();

            tickets[idx]--;
            if(tickets[idx]>0)
            {
                q.push(idx);
            }
            t++;
        }
        return t;
    }
};