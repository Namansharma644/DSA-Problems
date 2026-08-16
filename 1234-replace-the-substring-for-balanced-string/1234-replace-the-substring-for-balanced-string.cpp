class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int required = n / 4;

        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        if (mp['Q'] == required &&
        mp['W'] == required &&
        mp['E'] == required &&
        mp['R'] == required)
            return 0;

        int i = 0;
        int j=0;
        int ans = INT_MAX;

        while(j<n){

            mp[s[j]]--;

            while (i<=j && mp['Q'] <= required &&
                   mp['W'] <= required &&
                   mp['E'] <= required &&
                   mp['R'] <= required) {

                ans = min(ans, j - i + 1);

                mp[s[i]]++;
                i++;
            }
            j++;
        }

        return ans;
    }
};