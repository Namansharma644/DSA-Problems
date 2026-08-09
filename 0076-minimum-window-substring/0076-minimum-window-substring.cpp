class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        int n=s.size();

        if(m>n) return "";
        unordered_map<char,int>map;
        for(char &c : t)
        {
            map[c]++;
        }
        int i=0,j=0;
        int minLen=INT_MAX;
        int currRequired=m;
        int start=0;

        while(j<n)
        {
            char ch=s[j];
            if(map[ch]>0) currRequired--;
            map[ch]--;

            while(currRequired==0)
            {
                int currLen=j-i+1;

                if(currLen<minLen)
                {
                    minLen=currLen;
                    start=i;
                }

                map[s[i]]++;
                if(map[s[i]]>0) currRequired++;
                i++;
            }
            j++;
        }
        return (minLen==INT_MAX) ? "" : s.substr(start,minLen);
    }
};