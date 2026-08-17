class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k=tasks.size();
        vector<int>map(26,0);

        for(char &c : tasks)
        {
            map[c-'A']++;
        }

        sort(map.begin(),map.end());

        int maxFreq=map[25];
        int slots=maxFreq-1;
        int isolatedSlots=slots*n;

        for(int i=24; i>=0; i--)
        {
            isolatedSlots-=min(map[i],slots);
        }

        if(isolatedSlots<0)
        {
            return tasks.size();
        }

        return tasks.size()+isolatedSlots;
    }
};