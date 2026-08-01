class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int cumSum=0;
        int res=0;

        for(int i=0; i<n; i++)
        {
            cumSum+=nums[i];

            if(m.find(cumSum-k)!=m.end())
            {
                res+=m[cumSum-k];
            }

            m[cumSum]++;
        }
        return res;
    }
};