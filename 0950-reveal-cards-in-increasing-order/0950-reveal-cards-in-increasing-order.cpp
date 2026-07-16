class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        bool skip=false;
        int n=deck.size();
        vector<int>res(n,0);

        int idx=0;
        int j=0;
        while(idx<n)
        {
            if(res[j]==0)
            {
                if(skip==false)
                {
                    res[j]=deck[idx];
                    idx++;
                }

                skip=!skip;
            }

            j=(j+1)%n;
        }

        return res;
    }
};