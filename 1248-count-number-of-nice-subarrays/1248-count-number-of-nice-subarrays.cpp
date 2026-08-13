class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int ans=0;
        unordered_map<int,int>m;
        m[0]=1;

        for(int i=0; i<n; i++)
        {
            if(nums[i]%2!=0)
            {
                count++;
            }

            if(m.find(count-k)!=m.end())
            {
                ans+=m[count-k];
            }

            m[count]++;
        }

        return ans;
    }
};