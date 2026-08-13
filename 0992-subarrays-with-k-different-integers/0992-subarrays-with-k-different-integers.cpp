class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int f=0;
        unordered_map<int,int>m;
        int ans=0;

        while(j<n)
        {
            m[nums[j]]++;

            while(m.size()>k)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                {
                    m.erase(nums[i]);
                }
                i++;
                f=i;
            }

            while(m[nums[i]]>1)
            {
               m[nums[i]]--;
               i++;
            }

            if(m.size()==k)
            {
                ans+=(1+(i-f));
            }
            j++;
        }
        
        return ans;
    }
};