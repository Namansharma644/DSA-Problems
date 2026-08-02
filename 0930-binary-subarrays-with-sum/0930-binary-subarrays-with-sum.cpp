class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int res=0;
        int currSum=0;
        int i=0,j=0;
        int currZero=0;

        while(j<n)
        {
            currSum+=nums[j];

            while(i<j && (nums[i]==0 || currSum>goal))
            {
                 (nums[i]==0) ? currZero++ : currZero=0;
                 currSum-=nums[i];
                 i++;
            }

            if(currSum==goal)
            {
                res+=(1+currZero);
            }

            j++;
        }
        return res;
    }
};