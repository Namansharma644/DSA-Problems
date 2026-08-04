class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int>s;
        int largest=1;

        for(int i=0; i<n; i++)
        {
            s.insert(nums[i]);
        }

        for(auto &it : s)
        {
            if(s.find(it-1)==s.end())
            {
                int x=it;
                int count=1;
                while(s.find(x+1)!=s.end())
                {
                    x=x+1;
                    count++;
                }
                largest=max(largest,count);
            }
        }
        return largest;
    }
};