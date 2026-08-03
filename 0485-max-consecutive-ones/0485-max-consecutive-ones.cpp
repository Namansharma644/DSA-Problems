class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int consequtiveOnes=0;
        int res=0;

        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
            {
                consequtiveOnes++;
                res=max(res,consequtiveOnes);
            }
            else
            {
                consequtiveOnes=0;
            }
        }
        return res;
    }
};