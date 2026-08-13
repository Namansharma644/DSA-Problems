class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int>m;

        while(j<n)
        {
            m[fruits[j]]++;

            while(m.size()>2)
            {
                m[fruits[i]]--;
                if(m[fruits[i]]==0)
                {
                    m.erase(fruits[i]);
                }
                i++;
            }

            if(m.size()<=2)
            {
                ans=max(j-i+1,ans);
            }
            j++;
        }
        return ans;
    }
};