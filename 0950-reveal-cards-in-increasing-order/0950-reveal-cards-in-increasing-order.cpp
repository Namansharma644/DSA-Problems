class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        int n=deck.size();
        vector<int>res(n,0);

        for(int i=0; i<n; i++)
        {
            q.push(i);
        }

        int idx=0;
        while(idx<n)
        {
            int j=q.front();
            q.pop();

            res[j]=deck[idx];
            idx++;

            if(!q.empty())
            {
                int skipElement=q.front();
                q.pop();
                q.push(skipElement);
            }
        }

        return res;
    }
};