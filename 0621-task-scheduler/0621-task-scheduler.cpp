class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k=tasks.size();
        vector<int>map(26,0);

        for(char &c : tasks){
            map[c-'A']++;
        }

        int times=0;
        priority_queue<int>pq;

        for(int i=0; i<26; i++)
        {
            if(map[i]>0)
            {
                pq.push(map[i]);
            }
        }

        while(!pq.empty())
        {
            vector<int>temp;

            for(int i=1; i<=n+1; i++)
            {
                if(!pq.empty())
                {
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f  : temp)
            {
                if(f>0)
                {
                    pq.push(f);
                }
            }

            if(pq.empty())
            {
                times+=temp.size();
            }
            else
            {
                times+=(n+1);
            }
        }

        return times;
    }
};