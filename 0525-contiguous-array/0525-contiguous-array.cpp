class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int>m;
        m[0]=-1;
        int currSum=0;

        for(int i=0; i<n; i++)
        {
            currSum+=(nums[i]==1) ? 1 : -1;

            if(m.find(currSum)!=m.end())
            {
                res=max(res,i-m[currSum]);
            }
            else
            {
                m[currSum]=i;
            }
        }
        return res;
    }
};