class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool>vis(n+1,false);

        for(int i=0; i<n; i++)
        {
            if(nums[i]>0 && nums[i]<=n)
            {
                int idx=nums[i];
                vis[idx]=true;
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                return i;
            }
        }
        return n+1;
    }
};