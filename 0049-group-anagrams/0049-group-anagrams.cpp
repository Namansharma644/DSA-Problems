class Solution {
public:
    string genrateWord(string &word)
    {
        vector<int>freq(26,0);
        for(int i=0; i<word.size(); i++)
        {
            freq[word[i]-'a']++;
        }
        string s="";
        for(int i=0; i<26; i++)
        {
             if(freq[i]>0)
             {
                s+=string(freq[i],i+'a');
             }
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>map;
        vector<vector<string>>res;

        for(int i=0; i<n; i++)
        {
            string temp=strs[i];
            string new_temp=genrateWord(temp);
            map[new_temp].push_back(strs[i]);
        }

        for(auto &it : map)
        {
            res.push_back(it.second);
        }
        return res;
    }
};