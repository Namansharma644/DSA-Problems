class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int bestBuy=nums[0];
        int maxProfit=0;

        for(int i=1; i<n; i++)
        {
            if(nums[i]>bestBuy)
            {
                maxProfit=max(maxProfit,nums[i]-bestBuy);
            }

            bestBuy=min(bestBuy,nums[i]);
        }
        return maxProfit;
    }
};