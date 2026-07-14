class Solution {
public:
    bool check(string &senate,int idx,char ch)
    {
        bool checkLeft=false;

        while(true)
        {
            if(idx==0)
            {
                checkLeft=true;
            }

            if(senate[idx]==ch)
            {
                senate.erase(senate.begin()+idx);
                break;
            }

            idx=(idx+1)%(senate.size());
        }
     return checkLeft;
    }
    string predictPartyVictory(string senate) {
        
        int idx=0;
        int Rcount=count(senate.begin(),senate.end(),'R');
        int Dcount=senate.size()-Rcount;

        while(Rcount>0 && Dcount>0)
        {
            bool checkLeft=false;
            if(senate[idx]=='R')
            {
                checkLeft=check(senate,(idx+1)%(senate.size()),'D');
                Dcount--;
                if(checkLeft)
                {
                    idx--;
                }
            }
            else
            {
                checkLeft=check(senate,(idx+1)%(senate.size()),'R');
                Rcount--;
                if(checkLeft)
                {
                    idx--;
                }
            }
            
            idx=(idx+1)%(senate.size());
        }
        return (Rcount==0) ? "Dire" : "Radiant";
    }
};