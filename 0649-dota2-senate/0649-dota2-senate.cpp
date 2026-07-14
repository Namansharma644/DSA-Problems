class Solution {
public:
    void check(string &senate,int idx,char ch,vector<bool>&remove)
    {
        while(true)
        {
            
            if(senate[idx]==ch && remove[idx]==false)
            {
                remove[idx]=true;
                break;
            }

            idx=(idx+1)%(senate.size());
        }
    }
    string predictPartyVictory(string senate) {
        
        int idx=0;
        int Rcount=count(senate.begin(),senate.end(),'R');
        int Dcount=senate.size()-Rcount;
        vector<bool>remove(senate.size(),false);

        while(Rcount>0 && Dcount>0)
        {
            if(remove[idx]==false)
            {
                if(senate[idx]=='R')
                {
                    check(senate,(idx+1)%(senate.size()),'D',remove);
                    Dcount--;
                }
                else
                {
                    check(senate,(idx+1)%(senate.size()),'R',remove);
                    Rcount--;
                }  
            }
            idx=(idx+1)%(senate.size());
        }
        return (Rcount==0) ? "Dire" : "Radiant";
    }
};