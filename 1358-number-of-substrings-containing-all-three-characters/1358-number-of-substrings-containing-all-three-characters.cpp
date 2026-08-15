class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<int>map(3,0);
        int i=0;
        int j=0;

        while(j<n)
        {
            map[s[j]-'a']++;

            while(map[0]>0 && map[1]>0 && map[2]>0)
            {
                count+=n-j;

                map[s[i]-'a']--;
                i++;
            }

            j++;
        }
        return count;
    }
};