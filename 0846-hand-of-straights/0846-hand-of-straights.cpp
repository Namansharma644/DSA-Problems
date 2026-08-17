class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int>m;

        if(n%groupSize!=0) return false;

        for(int &a : hand)
        {
            m[a]++;
        }

        while(m.size()>0)
        {
            int curr=m.begin()->first;

            for(int i=0; i<groupSize; i++)
            {
                if(m[curr+i]==0)
                {
                    return false;
                }

                m[curr+i]--;
                if(m[curr+i]==0)
                {
                    m.erase(curr+i);
                }
            }
        }

        return true;
    }
};